#!/usr/bin/env python3
import subprocess
import os
import re
import sys

EXEC = "./btc"
TEST_FILE = "tmp_tester_input.txt"

class C:
    GREEN = '\033[92m'
    RED = '\033[91m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    RESET = '\033[0m'
    BOLD = '\033[1m'

tests = [
    {
        "name": "1. Subject base example",
        "input": """date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
""",
        "check": lambda out: (
            out.count("=>") >= 5 and 
            "ERROR" in out and 
            "2011-01-03 => 3 = 0.9" in out and 
            "2012-01-11 => 1 = 7.1" in out
        ),
        "desc": "Vérifie les données exactes de l'exemple du sujet."
    },
    {
        "name": "2. Invalid dates (Calendar)",
        "input": """date | value
2012-02-30 | 5
2011-02-29 | 5
2011-04-31 | 5
2022-13-01 | 5
2022-00-01 | 5
2022-01-00 | 5
""",
        "check": lambda out: (out.lower().count("error") >= 6),
        "desc": "Toutes les dates sont invalides (mois/jours hors limites), doit afficher des erreurs."
    },
    {
        "name": "3. Valid dates (Leap years & Limits)",
        "input": """date | value
2012-02-29 | 1
2011-04-30 | 1
""",
        "check": lambda out: ("Error" not in out and out.count("=>") == 2),
        "desc": "Année bissextile (2012) et dernier jour d'avril. Ne doit afficher aucune erreur."
    },
    {
        "name": "4. Value Limits (0 to 1000)",
        "input": """date | value
2012-01-11 | 0
2012-01-11 | 1000
2012-01-11 | -0.1
2012-01-11 | 1001
2012-01-11 | 1000.1
""",
        "check": lambda out: (
            ("not a positive number" in out.lower() or "too low value" in out.lower()) and 
            ("too large a number" in out.lower() or "too large value" in out.lower()) and 
            out.count("=>") >= 2
        ),
        "desc": "Vérifie les bornes 0 et 1000 inclus, et attend 'Error: not a positive number.' ou 'Error: too large a number.' pour le reste."
    },
    {
        "name": "5. Format Errors",
        "input": """date | value
bad format line
2012-01-11 |
| 5
2012-01-11 | abc
""",
        "check": lambda out: ("parsing error" in out.lower() and out.lower().count("error") >= 3),
        "desc": "Lignes mal formatées. Attend 'Error: bad input => [ligne]' selon le sujet."
    },
    {
        "name": "6. Empty file",
        "input": "",
        "check": lambda out: True, # Any behavior is fine (error or empty)
        "desc": "Fichier vide. Le programme ne doit pas segfault / planter."
    },
    {
        "name": "7. Future date",
        "input": """date | value
2030-01-01 | 1
""",
        "check": lambda out: ("=>" in out or "error" in out.lower()),
        "desc": "Date dans le futur. Doit prendre la date la plus récente connue, ou faire une erreur explicite."
    },
    {
        "name": "8. Too old date",
        "input": """date | value
2008-01-01 | 1
""",
        "check": lambda out: ("error" in out.lower()),
        "desc": "Date antérieure à la base de données. Doit afficher une erreur (car aucune date inférieure n'existe)."
    }
]

def run():
    if not os.path.exists(EXEC):
        print(f"{C.RED}Error: Executable '{EXEC}' not found.{C.RESET}")
        print(f"Please run 'make' first.")
        sys.exit(1)

    print(f"{C.BOLD}{C.BLUE}=== BTC EX00 AUTOMATED TESTER ==={C.RESET}")
    print("Testing edge cases, validity, outputs and error handling...")
    print("---------------------------------------------------------")

    score = 0
    
    for i, test in enumerate(tests):
        with open(TEST_FILE, "w") as f:
            f.write(test["input"])
            
        print(f"{C.BOLD}{test['name']}{C.RESET}")
        print(f"↳ {test['desc']}")

        try:
            res = subprocess.run([EXEC, TEST_FILE], capture_output=True, text=True, timeout=2)
            out = (res.stdout + res.stderr).strip()
            
            if test["check"](out):
                print(f"[{C.GREEN}PASS{C.RESET}] Le comportement semble correct.")
                score += 1
            else:
                print(f"[{C.RED}FAIL{C.RESET}] Le comportement inattendu détecté.")
            
            # Print output nicely indented
            if out:
                print(f"{C.YELLOW}Output:{C.RESET}")
                for line in out.split('\n'):
                    print(f"  {line}")
            else:
                print(f"{C.YELLOW}Output:{C.RESET} (empty)")

        except subprocess.TimeoutExpired:
            print(f"[{C.RED}FAIL{C.RESET}] Timeout (Infinite loop ?)")
        except Exception as e:
            print(f"[{C.RED}FAIL{C.RESET}] Error: {e}")
            
        print("-" * 50)

    # Test file that does not exist
    print(f"{C.BOLD}9. File does not exist / Permissions{C.RESET}")
    print("↳ Teste l'ouverture d'un fichier inexistant.")
    res = subprocess.run([EXEC, "this_file_does_not_exist.txt"], capture_output=True, text=True)
    out = (res.stdout + res.stderr).strip()
    if "error" in out.lower() or "could not open" in out.lower():
        print(f"[{C.GREEN}PASS{C.RESET}]")
        score += 1
    else:
        print(f"[{C.RED}FAIL{C.RESET}]")
    print(f"{C.YELLOW}Output:{C.RESET}\n  {out if out else '(empty)'}")
    print("-" * 50)
    
    total = len(tests) + 1
    
    print(f"{C.BOLD}=== RESULTS: {score}/{total} PASS ==={C.RESET}\n")

    if os.path.exists(TEST_FILE):
        os.remove(TEST_FILE)

if __name__ == "__main__":
    run()

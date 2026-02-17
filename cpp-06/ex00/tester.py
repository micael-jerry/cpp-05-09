#!/usr/bin/env python3
import subprocess
import sys
import os

# ANSI Colors
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
RESET = "\033[0m"

PROJ_DIR = os.path.dirname(os.path.realpath(__file__))
EXECUTABLE = os.path.join(PROJ_DIR, "convert")


def print_status(msg, color=RESET):
    print(f"{color}{msg}{RESET}")


def run_command(cmd, cwd=None):
    try:
        result = subprocess.run(
            cmd,
            shell=True,
            cwd=cwd,
            check=False,  # We handle return codes manually
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        return result.stdout.strip(), result.stderr.strip(), result.returncode
    except Exception as e:
        return "", str(e), -1


def compile_project():
    print_status(">>> Compiling project with 'make re'...", CYAN)
    _, stderr, code = run_command("make re", cwd=PROJ_DIR)
    if code != 0:
        print_status("Compilation FAILED!", RED)
        print(stderr)
        sys.exit(1)
    print_status("Compilation SUCCESS!", GREEN)


def parse_output(output):
    """
    Parses the output of ./convert into a dictionary.
    Expected format:
    char: <value>
    int: <value>
    float: <value>
    double: <value>
    """
    res = {}
    lines = output.split('\n')
    for line in lines:
        if ':' in line:
            key, val = line.split(':', 1)
            res[key.strip()] = val.strip()
    return res


def check_match(key, expected, actual):
    if expected is None:
        return True
    return expected == actual


def run_test_case(input_arg, expected_outputs):
    print(f"Testing input: [{YELLOW}{input_arg}{RESET}] ... ", end="")

    cmd = f"{EXECUTABLE} '{input_arg}'"
    stdout, stderr, code = run_command(cmd)

    # Check for segfaults or nonzero exit (unless expected, but here we expect 0 usually)
    if code != 0:
        print(f"{RED}[KO] (Exit Code {code}){RESET}")
        print(f"Stderr: {stderr}")
        return False

    actual_outputs = parse_output(stdout)
    errors = []

    for key, expected_val in expected_outputs.items():
        if key not in actual_outputs:
            errors.append(f"Missing '{key}' in output.")
            continue

        actual_val = actual_outputs[key]
        if not check_match(key, expected_val, actual_val):
            errors.append(
                f"{key}: expected '{expected_val}', got '{actual_val}'")

    if not errors:
        print(f"{GREEN}[OK]{RESET}")
        return True
    else:
        print(f"{RED}[KO]{RESET}")
        for err in errors:
            print(f"  -> {err}")
        return False


# --- Test Definitions ---
# Each test is a tuple: (Input String, Dictionary of Expected Outputs)
TESTS = [
    # --- Characters ---
    ("'a'", {"char": "'a'", "int": "97", "float": "97.0f", "double": "97.0"}),
    ("'*'", {"char": "'*'", "int": "42", "float": "42.0f", "double": "42.0"}),

    # --- Integers ---
    ("0", {"char": "Non displayable", "int": "0",
     "float": "0.0f", "double": "0.0"}),
    ("42", {"char": "'*'", "int": "42", "float": "42.0f", "double": "42.0"}),
    ("-42", {"char": "Non displayable", "int": "-42",
     "float": "-42.0f", "double": "-42.0"}),
    ("2147483647", {"char": "impossible", "int": "2147483647",
     "float": "2.14748e+09.0f", "double": "2.14748e+09.0"}),
    ("-2147483648", {"char": "impossible", "int": "-2147483648",
     "float": "-2.14748e+09.0f", "double": "-2.14748e+09.0"}),

    # --- Floats ---
    ("0.0f", {"char": "Non displayable",
     "int": "0", "float": "0.0f", "double": "0.0"}),
    ("4.2f", {"char": "Non displayable",
     "int": "4", "float": "4.2f", "double": "4.2"}),
    ("-4.2f", {"char": "Non displayable", "int": "-4",
     "float": "-4.2f", "double": "-4.2"}),
    ("42.0f", {"char": "'*'", "int": "42",
     "float": "42.0f", "double": "42.0"}),

    # --- Doubles ---
    ("0.0", {"char": "Non displayable", "int": "0",
     "float": "0.0f", "double": "0.0"}),
    ("4.2", {"char": "Non displayable", "int": "4",
     "float": "4.2f", "double": "4.2"}),
    ("-4.2", {"char": "Non displayable", "int": "-4",
     "float": "-4.2f", "double": "-4.2"}),
    ("42.0", {"char": "'*'", "int": "42", "float": "42.0f", "double": "42.0"}),

    # --- Pseudo-literals ---
    ("nanf", {"char": "impossible", "int": "impossible",
     "float": "nanf", "double": "nan"}),
    ("inff", {"char": "impossible", "int": "impossible",
     "float": "inff", "double": "inf"}),
    ("+inff", {"char": "impossible", "int": "impossible",
     "float": "+inff", "double": "+inf"}),
    ("-inff", {"char": "impossible", "int": "impossible",
     "float": "-inff", "double": "-inf"}),
    ("nan", {"char": "impossible", "int": "impossible",
     "float": "nanf", "double": "nan"}),
    ("inf", {"char": "impossible", "int": "impossible",
     "float": "inff", "double": "inf"}),
    ("+inf", {"char": "impossible", "int": "impossible",
     "float": "+inff", "double": "+inf"}),
    ("-inf", {"char": "impossible", "int": "impossible",
     "float": "-inff", "double": "-inf"}),

    # --- Edge Cases & Overflows ---
    ("2147483648", {"char": "impossible", "int": "impossible",
     "float": "2.14748e+09f", "double": "2.14748e+09.0"}),
    ("-2147483649", {"char": "impossible", "int": "impossible",
     "float": "-2.14748e+09f", "double": "-2.14748e+09.0"}),

    # --- Invalid Inputs ---
    ("abc", {"char": "impossible", "int": "impossible",
     "float": "impossible", "double": "impossible"}),
    ("42.42.42", {"char": "impossible", "int": "impossible",
     "float": "impossible", "double": "impossible"}),
    ("", {"char": "impossible", "int": "impossible",
     "float": "impossible", "double": "impossible"}),
]


def main():
    compile_project()
    print_status("\n>>> Starting Tests...", CYAN)

    passed = 0
    total = len(TESTS)

    for inp, expected in TESTS:
        if run_test_case(inp, expected):
            passed += 1

    print("\n" + "="*30)
    if passed == total:
        print(f"{GREEN}SUMMARY: {passed}/{total} tests passed. EXCELLENT!{RESET}")
    else:
        print(f"{RED}SUMMARY: {passed}/{total} tests passed.{RESET}")
    print("="*30)


if __name__ == "__main__":
    main()

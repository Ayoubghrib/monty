import sys

# Stack to hold elements
stack = []

def push(argument):
    """
    Pushes an element to the stack.
    """
    try:
        value = int(argument)
        stack.append(value)
    except ValueError:
        print(f"L{line_number}: usage: push integer")
        sys.exit(1)

def pop():
    """
    Removes the top element from the stack.
    """
    if not stack:
        print(f"L{line_number}: can't pop an empty stack")
        sys.exit(1)
    else:
        stack.pop()

def add():
    """
    Adds the top two elements of the stack.
    """
    if len(stack) < 2:
        print(f"L{line_number}: can't add, stack too short")
        sys.exit(1)
    else:
        top = stack.pop()
        second_top = stack.pop()
        stack.append(second_top + top)

def pall():
    """
    Prints all the values on the stack, starting from the top.
    """
    for value in reversed(stack):
        print(value)

def pint():
    """
    Prints the value at the top of the stack, followed by a new line.
    """
    if not stack:
        print(f"L{line_number}: can't pint, stack empty")
        sys.exit(1)
    else:
        print(stack[-1])

def nop():
    """
    No operation; does nothing.
    """
    pass

# Mapping of opcodes to functions
opcode_functions = {
    "push": push,
    "pop": pop,
    "add": add,
    "pall": pall,
    "pint": pint,
    "nop": nop,
}

def parse_line(line):
    """
    Parse a line of input and execute the corresponding opcode function.
    """
    global line_number
    line_number += 1
    line = line.split('#')[0]  # Strip comments
    tokens = line.strip().split()
    if tokens:
        opcode = tokens[0].lower()  # Convert opcode to lowercase
        if opcode in opcode_functions:
            if len(tokens) > 1:
                opcode_functions[opcode](tokens[1])
            else:
                opcode_functions[opcode]()
        else:
            print(f"L{line_number}: Unknown opcode: {opcode}")
            sys.exit(1)

def monty_interpreter(filename):
    """
    Main function to interpret the Monty bytecode file.
    """
    global line_number
    line_number = 0
    with open(filename, 'r') as file:
        for line in file:
            parse_line(line)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python interpreter.py <filename>")
        sys.exit(1)
    monty_interpreter(sys.argv[1])


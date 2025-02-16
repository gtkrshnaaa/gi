# **Documentation: `.gi` Interpreter**  

## **Introduction**  
This interpreter allows users to run files with the `.gi` extension, supporting simple commands such as variable definition and printing output using `println()`.  

---

## **Features**  

1. **Variable Declaration** (`$variableName = "value";`)  
   - Variables are stored in memory during execution.  
   - Values must be strings enclosed in double quotes (`""`).  
   - Example:  
     ```
     $message = "Hello, World!";
     ```

2. **Printing Direct Strings with `println("text");`**  
   - Directly prints a string to the console.  
   - Example:  
     ```
     println("Hello, World!");
     ```

3. **Printing Variables with `println($variableName);`**  
   - Prints the stored value of a variable.  
   - If the variable is undefined, an error message is shown.  
   - Example:  
     ```
     $message = "Hello, World!";
     println($message);
     ```

4. **Executing Commands from a `.gi` File**  
   - The interpreter reads and executes each line from a `.gi` file.

---

## **Installation**  

### **1. Clone or Download the Source Code**  
If using **Git**, run:  
```sh
git clone https://github.com/user/repo.git
cd repo
```
Or manually download `gi.c` and `Makefile`.  

### **2. Build Using Makefile**  
Make sure **GCC** is installed. If not, install it:  
```sh
sudo apt update && sudo apt install gcc -y   # Ubuntu/Debian
```
Then, compile the program using:  
```sh
make
```
This will generate an executable file named `gi`.  

---

## **Running the Interpreter**  

### **1. Create a `.gi` Script**  
Create a script file, e.g., `script.gi`, with the following content:  
```
$message = "Hello, World!";
println($message);
println("This is an interpreter.");
```

### **2. Execute the Script**  
Run the script using:  
```sh
./gi script.gi
```
**Expected Output:**  
```
Hello, World!
This is an interpreter.
```

---

## **Cleaning Up**  
To remove the compiled binary, use:  
```sh
make clean
```

---

## **Error Messages**  
- `Syntax Error!` → Incorrect syntax in the `.gi` file.  
- `Undefined variable: variableName` → Trying to print an undeclared variable.  

---

## **Conclusion**  
The `.gi` interpreter is a simple yet functional tool for handling variables and printing output. If you want to add new features, modify `gi.c` and rebuild using `make`.  

🚀 **Happy coding!** 🚀

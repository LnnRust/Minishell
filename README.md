<div align="center">

```
███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝
```

*A minimal UNIX shell — built from scratch at École 42 Le Havre*

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norminette-passing-brightgreen?style=flat-square)](https://github.com/42School/norminette)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)](LICENSE)

</div>

---

## 📖 About

**Minishell** is a project from the 42 curriculum that challenges students to implement a functional UNIX shell in C. The goal is to deeply understand how a shell works — process creation, file descriptors, signals, and how the terminal interprets commands.

> *"The most important thing we've ever engineered is the shell."*

---

## ✨ Features

| Feature | Description |
|---|---|
| 🖥️ **Interactive prompt** | Displays a prompt and waits for user input |
| 📜 **Command history** | Navigate previous commands with `↑` / `↓` |
| 🔍 **PATH resolution** | Finds and executes binaries from `$PATH` |
| 🔗 **Pipes** | Chain commands with `\|` |
| ↩️ **Redirections** | `>`, `>>`, `<`, `<<` (heredoc) |
| 💬 **Quotes** | Handles single `'` and double `"` quotes |
| 🌍 **Environment variables** | Expands `$VAR` and `$?` |
| ⚡ **Signals** | `ctrl-C`, `ctrl-D`, `ctrl-\` behave like bash |
| 🔧 **Builtins** | Full implementation of all required builtins |

---

## 🔧 Builtins

```bash
echo    [-n]              # Print text to stdout
cd      [path]            # Change current directory
pwd                       # Print working directory
export  [name[=value]]    # Set environment variables
unset   [name]            # Remove environment variables
env                       # Print environment
exit    [status]          # Exit the shell
```

---

## 🚀 Getting Started

### Prerequisites

- `gcc` or `clang`
- `make`
- `readline` library

```bash
# macOS
brew install readline

# Linux (Debian/Ubuntu)
sudo apt-get install libreadline-dev
```

### Installation

```bash
git clone git@github.com:LnnRust/Minishell.git
cd Minishell
make
```

### Usage

```bash
./Minishell
```

```
minishell$ echo "Hello, World!"
Hello, World!
minishell$ ls -la | grep .c | wc -l
42
minishell$ export NAME=student && echo "Hi $NAME"
Hi student
minishell$ cat << EOF
> this is a heredoc
> EOF
this is a heredoc
minishell$ exit
```

---

## 📚 Resources

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/)
- [Writing Your Own Shell](https://www.cs.cornell.edu/courses/cs414/2004su/homework/shell/shell.html)
- [GNU Readline](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [The Linux Programming Interface — Michael Kerrisk](https://man7.org/tlpi/)

---

## 👥 Authors

aandreo
fbenech
memillet

---

## 📜 License

This project is part of the 42 curriculum. Do **not** copy or submit it as your own work.

---

<div align="center">

*Made with ☕ and way too many `segfaults` at 42*

</div>

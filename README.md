<div align="center">

# 📖 Get Next Line

### *Read a line from a file descriptor, one line at a time*

[![42 School](https://img.shields.io/badge/School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge)](https://github.com/42School/norminette)
![Grade](https://img.shields.io/badge/Grade-125%2F100-success?style=for-the-badge)

</div>

---

## 📋 Table of Contents

- [About](#-about)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Documentation](#-documentation)
- [Project Structure](#-project-structure)
- [Testing](#-testing)
- [Performance](#-performance)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🎯 About

**Get Next Line** is a 42 school project that challenges students to create a function that reads and returns a single line from a file descriptor. This project emphasizes understanding of:

-  Static variables in C
-  Memory management and dynamic allocation
-  File descriptor manipulation
-  Buffer management
-  Edge case handling

> This function can be used to read files line by line, handle standard input, or process data from multiple file descriptors simultaneously.

---

## ✨ Features

<table>
<tr>
<td>

### Core Functionality
-  Read from any file descriptor
-  Returns one line per call
-  Handles lines of any length
-  Configurable buffer size
-  Memory-leak free

</td>
<td>

### Bonus Features
-  Multiple FD support
-  Simultaneous file reading
-  Efficient memory usage
-  Handles edge cases

</td>
</tr>
</table>

---

## 🚀 Installation

### Prerequisites

```bash
gcc (GNU Compiler Collection)
make (optional)
```

### Quick Start

1. **Clone the repository**
```bash
git clone https://github.com/Adavitas/get_next_line.git
cd get_next_line
```

2. **Compile the project**

**Mandatory version:**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c -o gnl_test
```

**Bonus version (multiple FDs):**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus_test
```

### 🎛️ Buffer Size Configuration

You can customize the buffer size at compilation:

| Buffer Size | Use Case |
|-------------|----------|
| `1` | Testing extreme cases |
| `42` | Default (balanced) |
| `1024` | Large file optimization |
| `10000` | Maximum performance |

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c
```

---

## 💻 Usage

### Basic Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Don't forget to free!
    }
    close(fd);
    return (0);
}
```

### Reading from stdin

```c
char *line;

printf("Enter text (Ctrl+D to end):\n");
while ((line = get_next_line(0)) != NULL)
{
    printf("You entered: %s", line);
    free(line);
}
```

### Multiple File Descriptors (Bonus)

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);  // Read from file1
char *line2 = get_next_line(fd2);  // Read from file2
char *line3 = get_next_line(fd1);  // Continue from file1

free(line1);
free(line2);
free(line3);
```

---

## 📚 Documentation

### Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| `fd` | `int` | File descriptor to read from |

### Return Value

| Return | Description |
|--------|-------------|
| `char *` | The line read from the file descriptor (including `\n` if present) |
| `NULL` | End of file reached or error occurred |

### Behavior

- 🔸 Returns lines one at a time, preserving newline characters
- 🔸 Works with files, stdin, network sockets, pipes
- 🔸 Handles consecutive calls efficiently
- 🔸 Manages its own internal buffer using static variables

---

## 📁 Project Structure

```
get_next_line/
│
├──  get_next_line.c              # Main implementation
├──  get_next_line.h              # Header file
├──  get_next_line_utils.c        # Helper functions
│
├──  get_next_line_bonus.c        # Bonus: Multiple FD support
├──  get_next_line_bonus.h        # Bonus header
├──  get_next_line_utils_bonus.c  # Bonus utilities
│
└── 📖 README.md                    # This file
```

### Helper Functions

| Function | Purpose |
|----------|---------|
| `ft_strlen` | Calculate string length |
| `ft_strchr` | Find character in string |
| `ft_strjoin` | Concatenate strings |
| `ft_strdup` | Duplicate string |
| `ft_strlcpy` | Safe string copy |

---

## 🧪 Testing

### Manual Testing

Create a test file:
```bash
echo -e "Line 1\nLine 2\nLine 3" > test.txt
```

### Recommended Test Cases

| Test Case | Description |
|-----------|-------------|
|  Normal files | Standard text files with regular lines |
|  Empty files | Files with no content |
|  Only newlines | Files containing only `\n` characters |
|  Long lines | Lines exceeding buffer size |
|  Large files | Files with thousands of lines |
|  stdin | Reading from standard input |
|  Multiple FDs | Alternating between file descriptors |

### Buffer Size Testing

Test with various buffer sizes to ensure robustness:

```bash
# Small buffer
gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Medium buffer
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Large buffer
gcc -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c
```

---

## ⚡ Performance

### Time Complexity
- **Average Case:** O(n) where n is the line length
- **Buffer Reading:** O(BUFFER_SIZE) per read operation

### Space Complexity
- **Static Buffer:** O(remaining content)
- **Output Line:** O(line length)

### Optimization Tips

> 💡 **Pro Tip:** For large files, use a larger `BUFFER_SIZE` (1024-4096) to reduce system calls.

---

## 👨‍💻 Author

**Adavitas** - *42 Student*

[![GitHub](https://img.shields.io/badge/GitHub-Adavitas-181717?style=flat&logo=github)](https://github.com/Adavitas)

---


## 📝 License

This project is part of the 42 School curriculum.

---

*This project was created as part of the 42 School common core curriculum.*



ComputerScience
===============

Adventures in computer science  

Conventions:

- Doxygen comments where supported
- K&R style formatting 
- Java filenames begin with a capital letter.
    - Java filenames that start with a lowercase letter can cause problems during
packaging. 
- Other filenames are all lowercase.
- Use .hpp instead of .h for C++ headers
- Include guards for a file named filename.hpp look like:  
    `#ifdef FILENAME_HPP`
    - before the underscore is the uppercase filename stripped of any special symbols 
    - after the underscore is the uppercase extension
- Keep solutions to one self-contained file, if possible.
- Try to keep to 80 character lines. 
- Use `#include <file.h>` over `#include "file.h"` in accordance with JSF AV Rule 33 
- Classes always begin with a capital and use camel case.
- No tabs, only spaces
- 4 spaces per indent

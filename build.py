import sys

def generate_class_files(class_name):
    class_hpp_content = f'''#ifndef {class_name.upper()}_HPP
# define {class_name.upper()}_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class {class_name}
{{
	private:

	protected:

	public:
		{class_name}();
		~{class_name}();
		{class_name}(const {class_name}&);
		{class_name}& operator= (const {class_name}&);
}};

#endif
'''

    class_cpp_content = f'''#include "{class_name}.hpp"

{class_name}::{class_name}()
{{
	CLASS("Constructor", "{class_name}");
}}

{class_name}::~{class_name}()
{{
	CLASS("Destructor", "{class_name}");
}}

{class_name}::{class_name}(const {class_name}& other)
{{
	CLASS("Constructor by copy", "{class_name}");
	if (this == &other)
		return ;
}}

{class_name}& {class_name}::operator= (const {class_name}& other)
{{
	CLASS("Operand = Constructor", "{class_name}");
	if (this == &other)
		return (*this);
	return (*this);
}}
'''

    with open(f'{class_name}.hpp', 'w') as hpp_file:
        hpp_file.write(class_hpp_content)
    
    with open(f'{class_name}.cpp', 'w') as cpp_file:
        cpp_file.write(class_cpp_content)

	 # Read the Makefile and modify it
    with open('Makefile', 'r') as makefile:
        lines = makefile.readlines()
    
    # Find the index of the line containing "main.cpp"
    main_index = lines.index('SOURCES =\tmain.cpp \\\n')
    
    # Insert the class name after "main.cpp"
    lines.insert(main_index + 1, f'\t\t\t{class_name}.cpp \\\n')
    
    # Rewrite the Makefile with the updated lines
    with open('Makefile', 'w') as makefile:
        makefile.writelines(lines)

if len(sys.argv) != 2:
    print("Usage: python generate_class_files.py Class")
    sys.exit(1)

class_name = sys.argv[1]
generate_class_files(class_name)
print(f"Generated {class_name}.hpp and {class_name}.cpp")


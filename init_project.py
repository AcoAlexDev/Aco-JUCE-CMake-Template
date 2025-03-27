import os
import sys
import re
import shutil

def replace_in_file(file_path, old_text, new_text):
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            content = file.read()
        
        content = content.replace(old_text, new_text)
        
        with open(file_path, 'w') as file:
            file.write(content)

def main():
    if len(sys.argv) < 2:
        print("Usage: python init_project.py PROJECT_NAME")
        return
    
    project_name = sys.argv[1]
    
    # Replace in CMakeLists.txt
    replace_in_file('CMakeLists.txt', 'TEMPLATE_PROJECT', project_name)
    
    # Replace in source files
    for root, dirs, files in os.walk('Source'):
        for file in files:
            if file.endswith('.cpp') or file.endswith('.h'):
                file_path = os.path.join(root, file)
                replace_in_file(file_path, 'TEMPLATE_PROJECT', project_name)
    
    print(f"Project initialized as {project_name}")
    
if __name__ == "__main__":
    main()
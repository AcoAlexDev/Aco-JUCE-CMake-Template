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

def delete_template_files():
    files_to_delete = [
        'LICENSE.md',
        'README.md',
        '.gitattributes'
    ]
    
    for file in files_to_delete:
        if os.path.exists(file):
            os.remove(file)
            print(f"Deleted {file}")
    
    if os.path.exists('.github') and os.path.isdir('.github'):
        shutil.rmtree('.github')
        print("Deleted .github folder")

def main():
    if len(sys.argv) < 2:
        print("Usage: python init_project.py PROJECT_NAME")
        return
    
    project_name = sys.argv[1]
    
    replace_in_file('CMakeLists.txt', 'TEMPLATE_PROJECT', project_name)
    
    # Replaces TEMPLATE_PROJECT in all .cpp and .h files in the Source directory
    # Commented because it could break stuff
    # for root, dirs, files in os.walk('Source'):
    #     for file in files:
    #         if file.endswith('.cpp') or file.endswith('.h'):
    #             file_path = os.path.join(root, file)
    #             replace_in_file(file_path, 'TEMPLATE_PROJECT', project_name)

    delete_template_files()
    
    print(f"Project initialized as {project_name}")
    
if __name__ == "__main__":
    main()
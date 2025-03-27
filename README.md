# Juce CMake Template

This template was created to easily create new JUCE Projects with CMake support.
It was created on a Windows x64 PC and VSCode. With other machines and software it could not work as expected.

## Setting up own Template
### In CMakeLists.txt:
Change "C:/Users/User/Documents/JUCE" to your installed JUCE Folder Destination

Replace all common occurences of static information.
I suggest changing:

    COMPANY_NAME "Company" //Change your company details in Template
    COMPANY_COPYRIGHT "Copyright (c) 2025 Company"
    COMPANY_DOMAIN "company.com"
    COMPANY_WEBSITE "company.com"
    COMPANY_EMAIL "info@example.com"

Add your custom module uncomment and change the path to your user modules folder:<br>
set(CUSTOM_MODULES_PATH "C:/Users/User/OneDrive/Documents/JuceUserModules")<br>
juce_add_module(${CUSTOM_MODULES_PATH}/my_module)<br>
And also add plain my_module to the PRIVATE section in target_link_libraries.<br>

## Create a new project
Step 1: Copy this template<br>
Step 2: Download template and connect it with GitHub<br>
Step 3: Run init_project.py {PROJECT_NAME} to automatically update CMakeLists.txt
You can delete the python file now, if you want<br>
Setp 4: Change these in CMakeLists.txt; Watch out that CODE and MANUFACTURER_CODE are unique, 4 letters and first uppercase, rest lowercase

    PLUGIN_MANUFACTURER_CODE "Comp"
    PLUGIN_CODE "Aplg"
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "TEMPLATE_PROJECT"

## Usage after Setup
### In VSCode:
CMake should rebuild on every save<br>
Press Ctrl + Shift + P, select 'CMake Configure' and then 'debug' to build<br>

### In Visual Studio (How I'm doing it)
CMake rebuilds automatically when saving inside the file<br>
Press F5 to build and execute Standalone, VST3 is automatically safed in the correct folder<br>

## Adding Resources
New BinaryData Assets should be added in the Assets Folder<br>
New Scripts should be placed in Source/<br>
New Scripts with DSP code should be placed in Source/Dsp<br>

## License
MIT License

Copyright (c) 2025 AcoAlexDev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
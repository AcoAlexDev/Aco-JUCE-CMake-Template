# Juce CMake Template

This template was created to simplify the process of creating new [JUCE](https://juce.com/) Projects with CMake support.<br>
All user irrelevant files (LICENSE.md, README.md, CONTRIBUTING.md, .gitattributes and .github/) are not copied when creating a new repository.

It was developed on a Windows x64 PC using VSCode.<br>
Compatibility with other operating systems, IDEs, or software is not guaranteed.<br>

Feel free to fork this repository and submit pull requests.<br>
Contributions aimed at enhancing compatibility while maintaining simplicity are especially welcome.<br>

To learn more about CMake check the [TAP YouTube explanation](https://www.youtube.com/watch?v=FLP_AVbzueY)<br>
I plan to publish an elaborate YouTube tutorial on this template approximately one month after release, if any bugs persist.<br>

## Benefits
- Simplicity: Designed to minimize complexity, making it beginner-friendly.<br>
- Effortless Setup: Includes streamlined steps to get your project up and running with minimal hassle.<br>
- Direct GitHub Integration: Ensures seamless compatibility and setup for GitHub repositories.<br>
- Build Presets: Offers pre-configured debug and release presets for easy and efficient building, reducing the need for extensive terminal commands.<br>
- Lightweight: Includes only the essential files needed, keeping the setup minimal and efficient.<br>
- Forever free: This template will never become closed-source software, require payment, or offer limited features without payment.<br>

<br>

## File Overview
- CMakeLists.txt: Defines the build configuration for your JUCE project. This file includes paths, settings, and metadata necessary for compilation.<br>
- .gitignore: Prevents large, unneeded files from being uploaded to GitHub<br>
- CMakePresets.json: Instead of using tedious terminal commands, this file has two presets for debug and release export<br>
- init_project.py: Automatically configures CMakeLists.txt with your project name<br>
- bypass_image.png: Example image to demonstrate how a BinaryData asset is added in CMakeLists.txt<br>

<br>

## Setting up your own Template
- Step 1:<br>
    - Windows: Install [CMake](https://cmake.org/download/), [JUCE](https://juce.com/get-juce/) and [VSCode](https://code.visualstudio.com/download) / [Visual Studio](https://visualstudio.microsoft.com/vs/community/). Note: VS Studio has CMake support by default. One optional script needs [Python](https://www.python.org/downloads/)<br>
    - MacOS: Currently seeking contributions to add MacOS setup instructions.<br>
- Step 2: Copy this template with the green button on the top-right.<br>
- Step 3: Mark your newly created repository as a [template](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-template-repository) in the - repository settings.<br>
- Step 4: Download the repository and connect it to GitHub to modify the template.<br>

**In CMakeLists.txt:**<br>
Step 1: Change "C:/Users/User/Documents/JUCE" to your installed JUCE Folder Destination<br>

Step 2: Replace all occurrences of information that remains the same.<br>
I suggest changing:

    COMPANY_NAME "Company" //Change your company details in Template
    COMPANY_COPYRIGHT "Copyright (c) 2025 Company"
    COMPANY_DOMAIN "company.com"
    COMPANY_WEBSITE "company.com"
    COMPANY_EMAIL "info@example.com"

### Personalizing your template
- Feel free to change the default PluginEditor.h / .cpp and PluginProcessor.h / .cpp scripts based on your needs.
- Add your [custom juce modules](custom juce modules "Goto Custom Module")

## Create a new project
Step 1: Use this or your template as a starting point.<br>
Step 2: Download template and connect it to GitHub.<br>
Step 3: Run 'python init_project.py {PROJECT_NAME}' in the terminal to update CMakeLists.txt with project name details; 
You can delete the python file afterward if desired.<br>
Step 4: Update the following fields in CMakeLists.txt. Ensure that PLUGIN_CODE and PLUGIN_MANUFACTURER_CODE are unique, composed of four letters, with the first letter uppercase and the rest lowercase:

    PLUGIN_MANUFACTURER_CODE "Comp"
    PLUGIN_CODE "Aplg"
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "TEMPLATE_PROJECT" // Should already be set by init_python.py

Note:
In CMakeLists.txt, experienced users have the flexibility to customize JUCE modules according to their project's needs. They can remove unnecessary modules, modify existing ones, or add new ones as required. This allows for a tailored setup that optimizes project functionality while keeping the configuration lightweight and efficient.

## Usage after Setup
### In VSCode:
CMake automatically rebuilds on every save.<br>
Press Ctrl + Shift + P, select 'CMake Configure', then choose 'debug' to build.<br>

### In Visual Studio (How I'm doing it)
CMake automatically rebuilds when saving within the file.<br>
At the top of the window, make sure you select 'Standalone' to run.<br>
Press F5 to build and execute the standalone. VST3 is automatically saved in the correct folder.<br>

## Adding Scripts
Place new scripts in Source/<br>
Scripts containing DSP code, use Source/Dsp<br>

## Adding Resources
Add BinaryData assets in Assets/<br>
In CMakeLists.txt, add your new resource in this section:

    juce_add_binary_data(AudioPluginData
        SOURCES
            Assets/bypass_image.png)

## Tips & Tricks
### Juce Version Management
You can also create a folder with different JUCE Versions to avoid crashing plugins with newer JUCE versions, e.g.:<br>

C:/Users/User/Documents/JUCE<br>
├── JUCE 7.08<br>
└── JUCE 8<br>

This prevents plugins from automatically using the latest JUCE version (if updated in this folder), which can lead to crashes or system changes caused by JUCE updates.

### Juce Namespace
By default, building enables the JUCE namespace. To prevent this, I added a variable 'USE_JUCE_NAMESPACE' in CMakeLists.txt you can toggle to 'OFF'

### Custom Module
To add your custom module, uncomment and update the path to your user modules folder in CMakeLists.txt:<br>

    set(CUSTOM_MODULES_PATH "C:/Users/User/OneDrive/Documents/JuceUserModules")<br>
    juce_add_module(${CUSTOM_MODULES_PATH}/my_module)<br>

And add my_module to the PRIVATE section in target_link_libraries:<br>

    target_link_libraries(TEMPLATE_PROJECT
        PRIVATE
            juce::juce_audio_utils
            ...
            my_module)

### Other Templates
I know there are other templates for JUCE and CMake and I encourage you to have a look at them. 
I created this template based on my needs and features I need. <br>
The most widely-used and well documented template is probably [Pamplejuce](https://github.com/sudara/pamplejuce). In my opinion it has a lot of helpful features and it has been around for a long time.<br>

Another template I can recommend is the [one by Wolfsound](https://github.com/JanWilczek/audio-plugin-template) with a [youtube tutorial](https://www.youtube.com/watch?v=Uq7Hwt18s3s) setup.

If you want to create your fully own template have a look at [official JUCEs approach](https://github.com/juce-framework/JUCE/tree/master/examples/CMake/AudioPlugin)

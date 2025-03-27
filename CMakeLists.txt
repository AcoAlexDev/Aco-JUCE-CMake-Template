cmake_minimum_required(VERSION 3.22)

project(TEMPLATE_PROJECT VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#VARIABLES
set(USE_JUCE_NAMESPACE OFF)
set(JUCE_PATH "C:/Users/User/Documents/JUCE")

add_subdirectory(${JUCE_PATH} JUCE)

set(CUSTOM_MODULES_PATH "C:/Users/User/OneDrive/Dokumente/JuceUserModules")

juce_add_module(${CUSTOM_MODULES_PATH}/cmake_aco_universal_module_1)

# include(${JUCE_PATH}/extras/Build/CMake/JucePluginFunctions.cmake)

juce_add_plugin(TEMPLATE_PROJECT
    VERSION ${PROJECT_VERSION}
    COMPANY_NAME "Company"
    COMPANY_COPYRIGHT "Copyright (c) 2025 Company"
    COMPANY_DOMAIN "company.com"
    COMPANY_WEBSITE "company.com"
    COMPANY_EMAIL "info@example.com"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE "Comp"
    PLUGIN_CODE "Aplg"
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "TEMPLATE_PROJECT"
    PRODUCT_DESC "AudioPlugin"
    PLUGIN_VST3_CATEGORY "Fx" #|Distortion|Dynamics|EQ|Imaging|Modulation|Pitch Shift|Reverb|Spatial|Special|Utility
    # AU_MAIN_TYPE kAudioUnitType_MusicDevice
    # VST3_CATEGORIES "Instrument"
    # VST3_SUBCATEGORY "Instrument|Synth"
    # AAX_IDENTIFIER "com.company.aax.audioplugin"
    # AAX_CATEGORY AAX_ePlugInCategory_SWGenerators
    # AAX_IDENTIFER "com.company.aax.audioplugin"
    # AAX_CATEGORY AAX_ePlugInCategory_SWGenerators
    # ICON_BIG "Resources/icon.png"
    # ICON_SMALL "Resources/icon.png"
    FORMATS AU VST3 Standalone
    )

juce_add_binary_data(AudioPluginData
    SOURCES
        Assets/bypass_image.png
    )

target_include_directories(TEMPLATE_PROJECT
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
)

target_sources(TEMPLATE_PROJECT
    PRIVATE
        ${SOURCE_FILES}
)

target_link_libraries(TEMPLATE_PROJECT
    PRIVATE
        juce::juce_audio_utils
        juce::juce_audio_processors
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_dsp
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        juce::juce_opengl
        juce::juce_product_unlocking
        cmake_aco_universal_module_1
        AudioPluginData
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
    )

juce_generate_juce_header(TEMPLATE_PROJECT)

if (USE_JUCE_NAMESPACE)
    add_compile_definitions(DONT_SET_USING_JUCE_NAMESPACE = 0)
else()
    add_compile_definitions(DONT_SET_USING_JUCE_NAMESPACE = 1)
endif()

target_compile_definitions(TEMPLATE_PROJECT
        PUBLIC
            JUCE_WEB_BROWSER=0
            JUCE_USE_CURL=0
            JUCE_VST3_CAN_REPLACE_VST2=0
    )


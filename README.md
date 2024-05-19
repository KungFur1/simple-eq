# simple-eq

A solo-group project for my oop c++ university module. This is a code-along based on a tutorial from freeCodeCamp.org.

## Notes

### AudioPluginHost
- Windows doesn't have AudioUnit. It only needs VST3 for sound support.
- Windows also doesn't have AUAudioFilePlayer which allows to play audio files into your audio processsing plugin.
- Useful VST startup fix comment:
    - 43:30 [Part 5] Quick Tip for everyone wondering how to do that on Windows in Visual Studio (I use 2017) :
    In the Solution Explorer panel, right-click on the Project "[plugin name]_VST3" > Properties. Then go to "Debugging" and set Command to the path of your AudioPluginHost's DEBUG (!) Build executable (change "$(TargetPath)" to, for example, "C:\Juce\AudioPluginHost\Debug\AudioPluginHost.exe"). Set this Command for every configuration (Debug/Release) of PluginName_VST3. 
    Attention: This only affects the [PluginName]_VST3 project, not _StandalonePlugin. When you click Debug, VS will run whatever project is set as the main Startup project for this solution (by default it's _StandalonePlugin = the one printed bold in Solution Explorer), so run _VST3 directly via Right-Click>Debugging>Start (or assign _VST3 as the main Startup project).
    This way, Visual Studio will launch the AudioPluginHost.exe (which IIRC automatically loads the last saved .filtergraph file) and go into debugging mode - so breakpoints, logs etc should work, too.
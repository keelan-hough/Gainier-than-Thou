# Gainier-than-Thou
A simple gain plugin featuring a seperate class for processing and a hand-coded GUI

I made this as a lab in one of my university classes, however I decided to give hand coding GUI's an attempt. Inside I have used a simple slider that will feed the value into the main .cpp file, and updates the values in the "gain" class file accordingly
While developing I experimented with the Listener class from JUCE, but found that just using .onValueChange to be significantly simpler and so stuck with it.
The gain class itself is simple, using a method named "setGain" to take a value from the cpp file to the class, a "getGain" method to easily return the value if needed and a "process" method which just takes the samples coming in, and mulitplies them by the gain.

I hope the annotations make the project easy to understand, I found the JUCE Index quite hard to understand and none of the tutorials helped too much either, although that could boil down to version differences, especially since how GUI is done in JUCE has been changed significantly in recent updates.

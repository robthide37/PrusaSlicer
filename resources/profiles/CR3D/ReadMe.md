# Set the right extrusion

Older devices manufactured before November 2023 require absolute extrusion.
For example:
If you have

- a model after November 2023 you have to **check** the option.
- a model before November 2023 you have to **uncheck** the option.

## Background

Older devices may have hardware limitations that affect extrusion behavior. It's important to understand these considerations to ensure optimal performance.

## Extrusion Method

Newer devices support relative extrusion, which offers more flexibility. However, older devices may require absolute extrusion to function correctly.

## Action for Older Devices

Users with older devices should consider adjusting the `use_relative_e_distance` setting in the printer's preferences. Disabling this setting may improve compatibility and performance.

## How to Adjust `use_relative_e_distance`

1. Navigate to the printer settings.
2. Set the mode to 'Expert' and make sure you are in the 'General' section.
3. Scroll down to the bottom ('Advanced'), the first option is 'Use relative E distances'(`use_relative_e_distance`).
4. Toggle the setting to enable or disable it based on device compatibility.
5. Save the changes to the printer model.

![Extrusion Consideration](placeholder_image.png)

/** @file
    @brief Lists all the connected displays.

    @date 2016

    @author
    Sensics, Inc.
    <http://sensics.com>

*/

// Copyright 2016 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Internal Includes
#include <display/DisplayEnumerator.h>

// Library/third-party includes
// - none

// Standard includes
#include <iostream>

inline std::string to_string(osvr::display::Rotation rotation)
{
    switch (rotation) {
    case osvr::display::Rotation::Zero:
        return "Landscape";
    case osvr::display::Rotation::Ninety:
        return "Portrait";
    case osvr::display::Rotation::OneEighty:
        return "Landscape (flipped)";
    case osvr::display::Rotation::TwoSeventy:
        return "Portrait (flipped)";
    }
}

int main(int argc, char* argv[])
{
    auto displays = osvr::display::getDisplays();

    for (const auto& display : displays) {
        using std::cout;
        using std::endl;

        cout << "Display: " << display.name << endl;
        cout << "  Adapter: " << display.adapter.description << endl;
        cout << "  Monitor name: " << display.name << endl;
        cout << "  Resolution: " << display.size.width << "x" << display.size.height << endl;
        cout << "  Position: (" << display.position.x << ", " << display.position.y << ")" << endl;
        cout << "  Rotation: " << to_string(display.rotation) << endl;
        cout << "  Refresh rate: " << display.verticalRefreshRate << endl;
        cout << "  " << (display.attachedToDesktop ? "Extended mode" : "Direct mode") << endl;
        cout << "  EDID vendor ID: " << display.edidVendorId << endl;
        cout << "  EDID product ID: " << display.edidProductId << endl;
        cout << "" << endl;
    }

    return 0;
}


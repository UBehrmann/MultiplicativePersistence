//
// Created by ursbe on 16.09.2023.
//

#include "MP_Window.h"
#include "../../MP/MultiplicativePersistence.h"

using namespace ImGui;

MP_Window::MP_Window(ImGuiID dockspaceID) : dockspaceID(dockspaceID) {

    data.load();

    highest = data.getNumbers().size();

    window_flags = ImGuiWindowFlags_MenuBar;
}

void MP_Window::update(bool *visible) {

    SetNextWindowDockID(dockspaceID, ImGuiCond_Always);

    Begin("Multiplicative Persistence", visible, window_flags);

    // Menu on the top left
    menuBar();

    // Multiplicative Persistence fonction
    if (startMP) {
        doMultiplicativePersistence();
    }

    dataTable();

    End();
}

void MP_Window::menuBar() {
    if (BeginMenuBar()) {
        if (BeginMenu("Options")) {
            // Menu Bar Options

            if (MenuItem("Save", "CTRL+S", false, true)) {
                data.save();
            }

            if (MenuItem("Load", "CTRL+L", false, true)) {
                data.load();
            }

            if (MenuItem("Start / stop", "CTRL+R", false, true)) {
                startMP = !startMP;
            }

            EndMenu();
        }

        EndMenuBar();
    }
}

void MP_Window::shutdown() {

    data.save();
}

void MP_Window::dataTable() {

    ImGuiTableFlags flags = ImGuiTableFlags_None;

    if (BeginTable("table", 3)) {

        TableSetupColumn("Step", flags);

        TableSetupColumn("Number", flags);

        TableHeadersRow();

        std::vector<MultiPers> numbers = data.getNumbers();

        // Show the lowest number for each step number
        for (size_t i = 0; i < numbers.size(); i++) {
            TableNextRow();
            TableNextColumn();
            Text("%2zu", i + 1);
            TableNextColumn();
            Text("%20llu", numbers[i]);
        }

        // Show current number being tested
        TableNextRow();
        TableNextColumn();
        Text("Current Number:");
        TableNextColumn();
        Text("%20llu", data.getNumber());

        EndTable();
    }
}

void MP_Window::doMultiplicativePersistence() {

    MultiPers steps = MultiplicativePersistence(data.getNumber());

    if (steps > highest) {
        data.addNumber(data.getNumber());
        highest = steps;
    }

    data.numberAddOne();
}
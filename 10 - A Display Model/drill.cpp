#include "Headers/Simple_window.h"
#include "Headers/Graph.h"
#include "Headers/Point.h"
#include "Headers/Window.h"

int main() {

    using namespace Graph_lib;

    Application App;

    Point tl {900,500};

    Simple_window win {tl, 600, 400, "My window"};

    win.wait_for_button();
}


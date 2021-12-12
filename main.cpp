#include "src/mainwindow.h"
#include <gtkmm/application.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.ftk.base");

    return app->make_window_and_run<MainWindow>(argc, argv);
}

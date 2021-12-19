#include "mainwindow.h"
#include <gtkmm-4.0/gtkmm/application.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.mattes.Cryptographer");
    return app->make_window_and_run<MainWindow>(argc, argv);
}

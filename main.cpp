#include "src/FormBase.h"
#include <gtkmm/application.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.ftk.base");

    return app->make_window_and_run<FormBase>(argc, argv);
}

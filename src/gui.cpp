//
// Created by karthikeyan on 08/12/20.
//

#include <elements.hpp>
using namespace cycfi::elements;

// Main window background color
auto constexpr bkd_color = rgba(35, 35, 37, 255);
auto background = box(bkd_color);

int imshow()
{
    app _app();
    window _win(_app.name());
    _win.on_close = [&_app]() { _app.stop(); };

    view view_(_win);

    view_.content(
            background
    );

    _app.run();
    return 0;
}

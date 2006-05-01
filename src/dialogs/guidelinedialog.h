/**
 *
 * \brief  Dialog for modifying guidelines
 *
 * Author:
 *   Andrius R. <knutux@gmail.com>
 *
 * Copyright (C) 2006 Authors
 *
 * Released under GNU GPL.  Read the file 'COPYING' for more information
 */

#ifndef INKSCAPE_DIALOG_GUIDELINE_H
#define INKSCAPE_DIALOG_GUIDELINE_H

#include <gtkmm/dialog.h>
#include <gtkmm/table.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/label.h>
#include <gtkmm/stock.h>
#include <gtkmm/adjustment.h>
#include "ui/widget/button.h"

namespace Inkscape {
namespace UI {
namespace Dialogs {

class GuidelinePropertiesDialog : public Gtk::Dialog {
public:
    GuidelinePropertiesDialog(SPGuide *guide, SPDesktop *desktop);
    virtual ~GuidelinePropertiesDialog();

    Glib::ustring     getName() const { return "LayerPropertiesDialog"; }

    static void showDialog(SPGuide *guide, SPDesktop *desktop);

protected:
    void _setup();

    void _onApply();
    void _onOK();
    void _onDelete();

    void _response(gint response);
    void _modeChanged();

private:
    GuidelinePropertiesDialog(GuidelinePropertiesDialog const &); // no copy
    GuidelinePropertiesDialog &operator=(GuidelinePropertiesDialog const &); // no assign

    SPDesktop *_desktop;
    SPGuide *_guide;
    Gtk::Table  _layout_table;
    Gtk::Label  _label_descr;
    Gtk::Label  _label_move;
    Inkscape::UI::Widget::CheckButton _relative_toggle;
    Gtk::Adjustment _adjustment;
    Gtk::SpinButton _spin_button;

    Gtk::Widget *_unit_selector;
    bool _mode;
    gdouble _oldpos;
};

} // namespace
} // namespace
} // namespace


#endif // INKSCAPE_DIALOG_GUIDELINE_H

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99 :

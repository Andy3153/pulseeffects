/*
 *  Copyright © 2017-2020 Wellington Wallace
 *
 *  This file is part of PulseEffects.
 *
 *  PulseEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PulseEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PulseEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef PITCH_UI_HPP
#define PITCH_UI_HPP

#include "plugin_ui_base.hpp"

class PitchUi : public Gtk::Grid, public PluginUiBase {
 public:
  PitchUi(BaseObjectType* cobject,
          const Glib::RefPtr<Gtk::Builder>& builder,
          const std::string& schema,
          const std::string& schema_path);
  PitchUi(const PitchUi&) = delete;
  auto operator=(const PitchUi&) -> PitchUi& = delete;
  PitchUi(const PitchUi&&) = delete;
  auto operator=(const PitchUi &&) -> PitchUi& = delete;
  ~PitchUi() override;

  void reset() override;

 private:
  Gtk::ToggleButton *faster = nullptr, *formant_preserving = nullptr;

  Glib::RefPtr<Gtk::Adjustment> cents, crispness, semitones, octaves, input_gain, output_gain;
};

#endif

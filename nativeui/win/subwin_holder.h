// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WIN_SUBWIN_HOLDER_H_
#define NATIVEUI_WIN_SUBWIN_HOLDER_H_

#include "nativeui/win/window_impl.h"

namespace base {
template<typename T> struct DefaultSingletonTraits;
}

namespace nu {

// Windows does not allow a child window to created without a parent, so this
// window becomes the temporary parent for the SubwinView childs that are not
// added to any parent yet.
class SubwinHolder : public WindowImpl {
 public:
  static SubwinHolder* GetInstance();

 protected:
  CR_BEGIN_MSG_MAP_EX(SubwinHolder, WindowImpl)
    CR_MSG_WM_COMMAND(OnCommand)
  CR_END_MSG_MAP()

  // Some controls cache their parents, so after we reparent some controls to
  // a new window, they would still send WM_COMMAND messages to this holder.
  // We need to redirect the messages just like the toplevel window.
  void OnCommand(UINT code, int command, HWND window);

 private:
  friend struct base::DefaultSingletonTraits<SubwinHolder>;

  SubwinHolder();
  ~SubwinHolder() override;
};

}  // namespace nu

#endif  // NATIVEUI_WIN_SUBWIN_HOLDER_H_

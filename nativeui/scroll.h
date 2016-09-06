// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_SCROLL_H_
#define NATIVEUI_SCROLL_H_

#include "nativeui/container.h"

namespace nu {

NATIVEUI_EXPORT class Scroll : public View {
 public:
  explicit Scroll(const Size& size);

  void SetContentView(Container* view);
  Container* GetContentView() const;

  void SetVerticalScrollBar(bool has);
  bool HasVerticalScrollBar() const;
  void SetHorizontalScrollBar(bool has);
  bool HasHorizontalScrollBar() const;
  void SetAutoHideScrollBar(bool is);
  bool IsScrollBarAutoHide() const;

 protected:
  ~Scroll() override;

  // Following platform implementations should only be called by wrappers.
  void PlatformInit(const Size& size);
  void PlatformSetContentView(Container* container);

 private:
  scoped_refptr<Container> content_view_;
};

}  // namespace nu

#endif  // NATIVEUI_SCROLL_H_
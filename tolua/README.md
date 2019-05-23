# Tolua时注意事项：

运行python genbindings_fairygui.py后，

直接使用附带的lua_fairygui_auto.cpp和.hpp替换，

或者直接使用这两个文件。

----

在tools/bindings-generator/targets/lua/conversions.yaml的ns_map中加入

> "fairygui::": "fgui."

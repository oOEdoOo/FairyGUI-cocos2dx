# Tolua时注意事项：

运行python genbindings_fairygui.py后，为了将传入的lua_function保存下来，需要修改以下几段代码

1. lua_fairygui_GList_setItemRenderer中的
> ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setItemRenderer");
>
>if(!ok)
>
改为
>
> arg0 = toluafix_ref_function(tolua_S, 2, 0);
>
> if(arg0 == 0)

2. lua_fairygui_GList_setPullDownCallback中的
> ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setPullDownCallback");
>
> if(!ok)
>
改为
>
> arg0 = toluafix_ref_function(tolua_S, 2, 0);
>
> if (arg0 == 0)

3. lua_fairygui_GList_setPullUpCallback中的
>
> ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setPullUpCallback");
>
> if(!ok)
>
改为
>
> arg0 = toluafix_ref_function(tolua_S, 2, 0);
>
> if (arg0 == 0)

4. lua_fairygui_GObject_addLuaClickCallback中的
>
> ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GObject:addLuaClickCallback");
>
> if(!ok)
>
改为
>
> arg0 = toluafix_ref_function(tolua_S, 2, 0);
>
> if (arg0 == 0)

5. lua_fairygui_GList_setOnItemClickCallback中的
>
> ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui.GList:setOnItemClickCallback");
>
> if(!ok)
>
改为
>
> arg0 = toluafix_ref_function(tolua_S, 2, 0);
>
> if (arg0 == 0)

----

在tools/bindings-generator/targets/lua/conversions.yaml的ns_map中加入

> "fairygui::": "fgui."

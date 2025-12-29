
Running as a plugin for LMMS:
```
cd lmms/plugins
ln -s [LRCScroll.lmms/plugin] LRCScroll

# cmake adjustment: edit lmms/cmake/modules
# edit: PluginList.cmake
# Add LRCScroll
```
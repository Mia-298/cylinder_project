# 快速开始

1. 编辑下位机config文件指定开机自动上线的设备

在*下位机项目*根目录下编辑`config/hyrms.json`文件
startup->dev_list填写`["<设备10位id>",<设备10位id>]`

2. 启动下位机

在*下位机项目*根目录下运行`make run_only`启动程序

3. 人工上下线设备/执行lua脚本(可选)

在*下位机项目*根目录下运行`make sql`启动调试程序

4. 启动sdk示例项目
在*本项目*根目录下运行`make run`编译并执行

# 升级sdk

升级前请自己备份原sdk包,可降级
在*本项目*根目录下执行`make install_sdk`

# 代码分析与提示

性能原因弃用c++ intellisense,使用 clangd 插件进行代码分析与提示

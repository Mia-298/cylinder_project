# third_party

根目录 `third_party` 是旧层级遗留目录，目前只保留：

```text
third_party/
└── onnxruntime/
```

当前 ROS2 工作空间内主要依赖统一放在：

```text
src/third_party/
├── OrbbecSDK_ROS2/
├── aubo_sdk/
└── onnxruntime/
```

新文档和新配置应优先参考 `src/third_party/README.md`。本目录下依赖自带的 README 不覆盖。

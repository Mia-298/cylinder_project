CMAKE_BASE_ARGS = -DCMAKE_C_COMPILER_LAUNCHER=ccache \
                  -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
			      -DCMAKE_CXX_FLAGS="-Wno-unknown-pragmas" \
			      -DCMAKE_CXX_STANDARD=17 \
			      -DCMAKE_CXX_STANDARD_REQUIRED=ON \
                  -G Ninja

CMAKE_EXT_ARGS = -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
				 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

ROS_SETUP=/opt/ros/humble/setup.sh

TARGET_PKG=cpp_proxy_test
TARGET_APP=cpp_proxy_test

.PHONY: run
run:
	@. $(ROS_SETUP) && \
	colcon build \
	--cmake-args $(CMAKE_BASE_ARGS) $(CMAKE_EXT_ARGS) \
	--event-handlers console_direct+ log+ status+ \
	--packages-up-to $(TARGET_PKG) \
	--cmake-force-configure
	@. ./install/setup.sh && \
	ros2 run $(TARGET_PKG) $(TARGET_APP) --config $(CONFIG_FILE) $(ARGS)

.PHONY: install_sdk
install_sdk:
	@cd src/ && \
	latest_sdk=$$(find . -maxdepth 1 -type f -name 'HyRMS_cpp_sdk_*.tar.gz' -printf '%f\n' | sort -r | head -n1); \
	if [ -z "$$latest_sdk" ]; then \
		echo "未找到sdk包:请把HyRMS_cpp_sdk_*.tar.gz放在项目src目录"; \
		exit 1; \
	fi; \
	latest_com=$$(find . -maxdepth 1 -type f -name 'HyRMS_com_export_*.tar.gz' -printf '%f\n' | sort -r | head -n1); \
	if [ -z "$$latest_com" ]; then \
		echo "未找到com接口包:请把HyRMS_com_export_*.tar.gz放在项目src目录"; \
		exit 1; \
	fi; \
	echo "正在覆盖sdk包: $$latest_sdk"; \
	rm -rf ./hyrms_export; \
	tar -xzvf "$$latest_sdk"; \
	echo "正在覆盖com包: $$latest_com"; \
	rm -rf ./com_interfaces; \
	tar -xzvf "$$latest_com";

.PHONY: clean_log
clean_log: 
	rm -rf ./log
	rm -rf ./Log

.PHONY: clean
clean:
	rm -rf ./build
	rm -rf ./install

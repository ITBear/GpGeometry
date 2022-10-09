TEMPLATE = subdirs

os_linux {
	SUBDIRS += \
		./GpGeometryCore
} else:os_android {
	SUBDIRS += \
		./GpGeometryCore
} else:os_ios {
	SUBDIRS += \
		./GpGeometryCore
} else:os_windows {
	SUBDIRS += \
		./GpGeometryCore
} else:os_macx {
	SUBDIRS += \
		./GpGeometryCore
} else:os_browser {
	SUBDIRS +=
} else {
	error("Unknown OS. Set CONFIG+=... one of values: os_linux, os_android, os_ios, os_windows, os_macx, os_browser, os_baremetal")
}

CONFIG += ordered

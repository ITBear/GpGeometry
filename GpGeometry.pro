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
    error("Unknown OS")
}

CONFIG += ordered

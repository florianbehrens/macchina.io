#
# Makefile
#
# $Id$
#
# Makefile for macchina.io web application launcher bundle
#

BUNDLE_TOOL = $(POCO_BASE)/OSP/BundleCreator/$(POCO_HOST_BINDIR)/bundle
PAGECOMPILER = $(POCO_BASE)/PageCompiler/$(POCO_HOST_BINDIR)/cpspc

include $(POCO_BASE)/build/rules/global

objects =  \
	LoginPage \
	ControllerRequestHandler \
	SessionJSON \
	Utility \
	AppRegistry \
	AppExtensionPoint \
	LauncherAppsJSON \
	BundleActivator

target         = io.macchina.webui.launcher
target_version = 1
target_libs    = PocoOSPWeb PocoOSP PocoNet PocoUtil PocoXML PocoFoundation

postbuild      = $(BUNDLE_TOOL) -n$(OSNAME) -a$(OSARCH) -Npng,gif,jpg -o../bundles Launcher.bndlspec

include $(POCO_BASE)/build/rules/dylib

# Rule for runnning PageCompiler
src/%.cpp: src/%.cpsp 
	@echo "** Compiling Page" $<
	$(PAGECOMPILER) --OSP $<

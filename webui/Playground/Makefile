#
# Makefile
#
# $Id$
#
# Makefile for macchina.io bundle administration utility
#

BUNDLE_TOOL = $(POCO_BASE)/OSP/BundleCreator/$(POCO_HOST_BINDIR)/bundle

include $(POCO_BASE)/build/rules/global

objects =  \
	SandboxRequestHandler \
	Utility \
	BundleActivator

target         = io.macchina.webui.playground
target_version = 1
target_libs    = PocoOSPWeb PocoOSP PocoNet PocoZip PocoUtil PocoJSON PocoXML PocoFoundation

postbuild      = $(BUNDLE_TOOL) -n$(OSNAME) -a$(OSARCH) -Npng,gif,jpg -o../bundles Playground.bndlspec

include $(POCO_BASE)/build/rules/dylib

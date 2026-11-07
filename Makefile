TOOLCHAIN = $(CURDIR)/cmake/toolchain.cmake
CLANG ?= $(firstword $(wildcard $(CURDIR)/llvm/bin/clang) $(wildcard $(shell brew --prefix llvm 2>/dev/null)/bin/clang) clang)
ROM ?= $(GRIMACE_ROM)
EXPORT_DLLS = addrstor asform ceshell commctrl commdlg coredll cxport htmlview imgdecmp inkx mlang mqoa msgstore msmqrt mshtml ndis ole32 oleaut32 richink secur32 shdocvw tnefutil toolhelp urlmon webview wininet winscard winsock
TARGETS = mips-ce1 mips-ce2 sh3-ce1 sh3-ce101 sh3-ce2 x86-ce2 arm-ce3

llvm = $(if $(GRIMACE_$(1)_LLVM),-DGRIMACE_LLVM_ROOT=$(GRIMACE_$(1)_LLVM))
llvm_clang = $(if $(GRIMACE_$(1)_LLVM),--clang $(GRIMACE_$(1)_LLVM)/bin/clang,--clang $(CLANG))

.PHONY: check examples debugmgr headers docstrings exports check-headers check-cxx-headers check-abi check-stdlib check-debugmgr clean

define target
.PHONY: examples-$(1) debugmgr-$(1)

examples-$(1):
	cmake -S examples -B build/$(1) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN) -DGRIMACE_ARCH=$(2) -DGRIMACE_CE_VERSION=$(3) $(call llvm,$(4))
	cmake --build build/$(1)

debugmgr-$(1):
	cmake -S debugmgr -B build/debugmgr/$(1) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN) -DGRIMACE_ARCH=$(2) -DGRIMACE_CE_VERSION=$(3) $(call llvm,$(4))
	cmake --build build/debugmgr/$(1)
endef

$(eval $(call target,mips-ce1,mips,1,MIPS))
$(eval $(call target,mips-ce2,mips,2,MIPS))
$(eval $(call target,sh3-ce1,sh3,1,SH3))
$(eval $(call target,sh3-ce101,sh3,1.01,SH3))
$(eval $(call target,sh3-ce2,sh3,2,SH3))
$(eval $(call target,x86-ce2,x86,2,X86))
$(eval $(call target,arm-ce3,arm,3,ARM))

check: check-abi check-cxx-headers check-stdlib check-debugmgr examples debugmgr

examples: $(addprefix examples-,$(TARGETS))

debugmgr: $(addprefix debugmgr-,$(TARGETS))

check-cxx-headers: check-cxx-headers-mips check-cxx-headers-sh3 check-cxx-headers-x86 check-cxx-headers-arm

check-cxx-headers-mips:
	python3 tests/check-cxx-headers.py --arch mips $(call llvm_clang,MIPS)

check-cxx-headers-sh3:
	python3 tests/check-cxx-headers.py --arch sh3 $(call llvm_clang,SH3)

check-cxx-headers-x86:
	python3 tests/check-cxx-headers.py --arch x86 $(call llvm_clang,X86)

check-cxx-headers-arm:
	python3 tests/check-cxx-headers.py --arch arm $(call llvm_clang,ARM)

check-headers:
	python3 tests/check-headers.py --arch mips $(call llvm_clang,MIPS)
	python3 tests/check-headers.py --arch sh3 $(call llvm_clang,SH3)
	python3 tests/check-headers.py --arch x86 $(call llvm_clang,X86)
	python3 tests/check-headers.py --arch arm $(call llvm_clang,ARM)

check-abi:
	python3 tests/check-abi.py $(call llvm_clang,ARM)

check-stdlib:
	cmake -S tests/stdlib -B build/check-stdlib -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN) -DGRIMACE_ARCH=arm $(call llvm,ARM)
	cmake --build build/check-stdlib

check-debugmgr:
	python3 tests/check-debugmgr.py

exports:
	python3 tools/cerom.py $(ROM) --exports exports/ce3-arm $(foreach dll,$(EXPORT_DLLS),--dll $(dll).dll)

headers:
	python3 tools/vendor-w32api.py $(GRIMACE_W32API)
	python3 tools/mksdk.py $(call llvm_clang,ARM)
	python3 tools/mkheaders.py --clang $(CLANG)
	python3 tools/mkconstants.py --clang $(CLANG)
	python3 tools/mksdkconstants.py $(call llvm_clang,ARM)
	python3 tools/mkdocs.py

docstrings:
	python3 tools/mkdocs.py

clean:
	rm -rf build

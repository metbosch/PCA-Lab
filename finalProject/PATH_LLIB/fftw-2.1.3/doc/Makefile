# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake 1.4 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = ..
prefix = /home2/users/alumnes/1160416/dades/PCA-Lab/finalProject/PATH_LLIB/fftw-2.1.3/installation
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/fftw
pkglibdir = $(libdir)/fftw
pkgincludedir = $(includedir)/fftw

top_builddir = ..

ACLOCAL = aclocal
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
host_alias = i686-pc-linux-gnu
host_triplet = i686-pc-linux-gnu
AS = @AS@
CC = gcc
CCthreads = 
DLLTOOL = @DLLTOOL@
F77 = 
FFTW_MPI_INCLUDELIST = 
FFTW_MPI_LIBLIST = 
FFTW_MPI_PROGLIST = 
FFTW_PREFIX = 
FFTW_THREADS_INCLUDELIST = 
FFTW_THREADS_LIBLIST = 
FFTW_THREADS_PROGLIST = 
FLIBS = 
LD = /usr/i586-suse-linux/bin/ld
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LN_S = ln
MAKEINFO = makeinfo
MPICC = gcc
MPILIBS = 
NM = /usr/bin/nm -B
OBJDUMP = @OBJDUMP@
PACKAGE = fftw
RANLIB = ranlib
SHARED_VERSION = 2.0.5
SHARED_VERSION_INFO = 2:5:0
THREADLIBS = 
VERSION = 2.1.3

info_TEXINFOS = fftw.texi

fftw_TEXINFOS = fftw.texi version.texi

HTML_FILES = equation-1.gif fftw_1.html fftw_4.html fftw_7.html 	fftw_foot.html equation-2.gif fftw_2.html fftw_5.html fftw_8.html 	fftw_toc.html equation-3.gif fftw_3.html fftw_6.html fftw_9.html         fftw_10.html equation-4.gif 


EXTRA_DIST = fftw.ps $(HTML_FILES) texi2html rfftwnd.fig rfftwnd.gif
PERL = perl
DVIPS = dvips -Z
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = ../fftw/config.h ../fftw/fftw.h
CONFIG_CLEAN_FILES = 
TEXI2DVI = texi2dvi
INFO_DEPS = fftw.info
DVIS = fftw.dvi
TEXINFOS = fftw.texi
DIST_COMMON =  $(fftw_TEXINFOS) Makefile.am Makefile.in mdate-sh \
stamp-vti texinfo.tex version.texi


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = gtar
GZIP_ENV = --best
all: all-redirect
.SUFFIXES:
.SUFFIXES: .dvi .info .ps .texi .texinfo .txi
$(srcdir)/Makefile.in: Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps doc/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


$(srcdir)/version.texi: stamp-vti
	@:

$(srcdir)/stamp-vti: fftw.texi $(top_srcdir)/configure.in
	@echo "@set UPDATED `$(SHELL) $(srcdir)/mdate-sh $(srcdir)/fftw.texi`" > vti.tmp
	@echo "@set EDITION $(VERSION)" >> vti.tmp
	@echo "@set VERSION $(VERSION)" >> vti.tmp
	@cmp -s vti.tmp $(srcdir)/version.texi \
	  || (echo "Updating $(srcdir)/version.texi"; \
	      cp vti.tmp $(srcdir)/version.texi)
	-@rm -f vti.tmp
	@cp $(srcdir)/version.texi $@

mostlyclean-vti:
	-rm -f vti.tmp

clean-vti:

distclean-vti:

maintainer-clean-vti:
	-rm -f $(srcdir)/stamp-vti $(srcdir)/version.texi

fftw.info: fftw.texi version.texi $(fftw_TEXINFOS)
fftw.dvi: fftw.texi version.texi $(fftw_TEXINFOS)


.texi.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texi.dvi:
	TEXINPUTS=.:$$TEXINPUTS \
	  MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2DVI) $<

.texi:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texinfo.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texinfo:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.texinfo.dvi:
	TEXINPUTS=.:$$TEXINPUTS \
	  MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2DVI) $<

.txi.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`

.txi.dvi:
	TEXINPUTS=.:$$TEXINPUTS \
	  MAKEINFO='$(MAKEINFO) -I $(srcdir)' $(TEXI2DVI) $<

.txi:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) `echo $< | sed 's,.*/,,'`
.dvi.ps:
	$(DVIPS) $< -o $@

install-info-am: $(INFO_DEPS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(infodir)
	@list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  d=$(srcdir); \
	  for ifile in `cd $$d && echo $$file $$file-[0-9] $$file-[0-9][0-9]`; do \
	    if test -f $$d/$$ifile; then \
	      echo " $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile"; \
	      $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile; \
	    else : ; fi; \
	  done; \
	done
	@$(POST_INSTALL)
	@if $(SHELL) -c 'install-info --version | sed 1q | fgrep -s -v -i debian' >/dev/null 2>&1; then \
	  list='$(INFO_DEPS)'; \
	  for file in $$list; do \
	    echo " install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file";\
	    install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file || :;\
	  done; \
	else : ; fi

uninstall-info:
	$(PRE_UNINSTALL)
	@if $(SHELL) -c 'install-info --version | sed 1q | fgrep -s -v -i debian' >/dev/null 2>&1; then \
	  ii=yes; \
	else ii=; fi; \
	list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  test -z "$ii" \
	    || install-info --info-dir=$(DESTDIR)$(infodir) --remove $$file; \
	done
	@$(NORMAL_UNINSTALL)
	list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  (cd $(DESTDIR)$(infodir) && rm -f $$file $$file-[0-9] $$file-[0-9][0-9]); \
	done

dist-info: $(INFO_DEPS)
	list='$(INFO_DEPS)'; \
	for base in $$list; do \
	  d=$(srcdir); \
	  for file in `cd $$d && eval echo $$base*`; do \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file; \
	  done; \
	done

mostlyclean-aminfo:
	-rm -f fftw.aux fftw.cp fftw.cps fftw.dvi fftw.fn fftw.fns fftw.ky \
	  fftw.kys fftw.ps fftw.log fftw.pg fftw.toc fftw.tp fftw.tps \
	  fftw.vr fftw.vrs fftw.op fftw.tr fftw.cv fftw.cn

clean-aminfo:

distclean-aminfo:

maintainer-clean-aminfo:
	cd $(srcdir) && for i in $(INFO_DEPS); do \
	  rm -f $$i; \
	  if test "`echo $$i-[0-9]*`" != "$$i-[0-9]*"; then \
	    rm -f $$i-[0-9]*; \
	  fi; \
	done
tags: TAGS
TAGS:


distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = doc

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
	$(MAKE) $(AM_MAKEFLAGS) top_distdir="$(top_distdir)" distdir="$(distdir)" dist-info
info-am: $(INFO_DEPS)
info: info-am
dvi-am: $(DVIS)
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am:
install-exec: install-exec-am

install-data-am: install-info-am
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-info
uninstall: uninstall-am
all-am: Makefile $(INFO_DEPS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(infodir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-vti mostlyclean-aminfo mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-vti clean-aminfo clean-generic mostlyclean-am \
		clean-local

clean: clean-am

distclean-am:  distclean-vti distclean-aminfo distclean-generic clean-am
	-rm -f libtool

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-vti maintainer-clean-aminfo \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-vti distclean-vti clean-vti maintainer-clean-vti \
install-info-am uninstall-info mostlyclean-aminfo distclean-aminfo \
clean-aminfo maintainer-clean-aminfo tags distdir info-am info dvi-am \
dvi check check-am installcheck-am installcheck install-exec-am \
install-exec install-data-am install-data install-am install \
uninstall-am uninstall all-redirect all-am all installdirs \
mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


html:	$(fftw_TEXINFOS) rfftwnd.gif
	$(PERL) texi2html -split_chapter -no_toc_href fftw.texi

$(HTML_FILES): html

# fig2dev gif output sucks.
# rfftwnd.gif: rfftwnd.fig
# 	fig2dev -L gif rfftwnd.fig rfftwnd.gif

fftw.ps: rfftwnd.eps

rfftwnd.eps: rfftwnd.fig
	fig2dev -L ps -m .7 rfftwnd.fig rfftwnd.eps

clean-local:
	rm -f *.html

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:

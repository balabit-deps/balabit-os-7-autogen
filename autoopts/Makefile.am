##  -*- Mode: Makefile -*-
##
## Author:          Bruce Korb <bkorb@gnu.org>
##
##  This file is part of AutoOpts, a companion to AutoGen.
##  AutoOpts is free software.
##  AutoOpts is Copyright (C) 1992-2016 by Bruce Korb - all rights reserved
##
##  AutoOpts is available under any one of two licenses.  The license
##  in use must be one of these two and the choice is under the control
##  of the user of the license.
##
##   The GNU Lesser General Public License, version 3 or later
##      See the files "COPYING.lgplv3" and "COPYING.gplv3"
##
##   The Modified Berkeley Software Distribution License
##      See the file "COPYING.mbsd"
##
##  These files have the following sha256 sums:
##
##  8584710e9b04216a394078dc156b781d0b47e1729104d666658aecef8ee32e95  COPYING.gplv3
##  4379e7444a0e2ce2b12dd6f5a52a27a4d02d39d247901d3285c88cf0d37f477b  COPYING.lgplv3
##  13aa749a5b0a454917a944ed8fffc530b784f5ead522b1aacaf4ec8aa55a6239  COPYING.mbsd

BUILT_SOURCES  	    =
MOSTLYCLEANFILES    =
libdatadir          = $(libdir)/@PACKAGE@
SUBDIRS             = @OPTS_TESTDIR@
AM_CPPFLAGS         = @INCLIST@
libsrc              = libopts-@AO_CURRENT@.@AO_REVISION@.@AO_AGE@.tar.gz
LIBOPTS_VER         = @AO_CURRENT@:@AO_REVISION@:@AO_AGE@

if  NEED_PATHFIND
PATHFIND_MAN    = pathfind.3
else
PATHFIND_MAN    =
endif

MAN_STAMP       = man3-stamp
GENTEXI         = libopts.texi libopts.menu
TEXI_STAMP      = texi-stamp
EXTRA_DIST      =
GENMAN          = $(PATHFIND_MAN) \
    ao_string_tokenize.3          configFileLoad.3 \
    optionFileLoad.3              optionFindNextValue.3 \
    optionFindValue.3             optionFree.3 \
    optionGetValue.3              optionLoadLine.3 \
    optionMemberList.3            optionNextValue.3 \
    optionOnlyUsage.3             optionPrintVersion.3 \
    optionPrintVersionAndReturn.3 optionProcess.3 \
    optionRestore.3               optionSaveFile.3 \
    optionSaveState.3             optionUnloadNested.3 \
    optionVersion.3               strequate.3 \
    streqvcmp.3                   streqvmap.3 \
    strneqvcmp.3                  strtransform.3

nodist_pkgdata_DATA = $(libsrc) \
    tpl/man2mdoc        tpl/man2texi        tpl/mdoc2man \
    tpl/mdoc2texi       tpl/texi2man        tpl/texi2mdoc \
    tpl/tpl-config.tlib

nodist_libdata_DATA = tpl/tpl-config.tlib

pkgdata_DATA    = \
    autoopts.m4         tpl/Mdoc.pm         tpl/aginfo.tpl \
    tpl/aginfo3.tpl     tpl/agman-cmd.tpl   tpl/agman-file.tpl \
    tpl/agman.tlib      tpl/agman1.tpl      tpl/agman3.tpl \
    tpl/agmdoc-cmd.tpl  tpl/agmdoc-file.tpl tpl/agpl.lic \
    tpl/agtexi-cmd.tpl  tpl/agtexi-file.tpl tpl/bits.tpl \
    tpl/cmd-doc.tlib    tpl/def2pot.tpl     tpl/getopt.tpl \
    tpl/gpl.lic         tpl/gplv2.lic       tpl/lgpl.lic \
    tpl/lgplv2.lic      tpl/mbsd.lic        tpl/optcode.tlib \
    tpl/opthead.tlib    tpl/options.tpl     tpl/optlib.tlib \
    tpl/optmain.tlib    tpl/perlopt.tpl     tpl/rc-sample.tpl \
    tpl/stdoptions.def  tpl/str2enum.tpl    tpl/str2init.tlib \
    tpl/str2mask.tpl    tpl/strings.tpl     tpl/usage.tlib

EXTRA_DATA      = $(pkgdata_DATA) \
    autogen.map            autoopts-config.in     bootstrap.dir \
    install-hook.sh        mk-autoopts-pc.in      mk-tpl-config.sh \
    po                     tpl/man2mdoc.pl        tpl/man2texi.sh \
    tpl/mdoc2man.pl        tpl/mdoc2texi.pl       tpl/texi2man.sh \
    tpl/texi2mdoc.sh       tpl/tpl-config-tlib.in

GENSCRIPTS      = $(srcdir)/funcs.def \
    tpl/man2man   tpl/man2mdoc  tpl/man2texi  tpl/mdoc2man  tpl/mdoc2mdoc \
    tpl/mdoc2texi tpl/texi2man  tpl/texi2mdoc tpl/texi2texi

EXTRA_DIST += $(top_srcdir)/config/gendocs.sh
EXTRA_DIST += gettext.h
EXTRA_DIST += intprops.h
EXTRA_DIST += parse-duration.c
EXTRA_DIST += parse-duration.h
# Because this Makefile snippet defines a variable used by other
# gnulib Makefile snippets, it must be present in all Makefile.am that
# need it. This is ensured by the applicability 'all' defined above.
_NORETURN_H=$(top_srcdir)/config/snippet/_Noreturn.h
EXTRA_DIST += $(top_srcdir)/config/snippet/_Noreturn.h
BUILT_SOURCES += $(STDNORETURN_H)
# We need the following in order to create <stdnoreturn.h> when the system
# doesn't have one that works.
if GL_GENERATE_STDNORETURN_H
stdnoreturn.h: stdnoreturn.in.h $(top_builddir)/config.status $(_NORETURN_H)
	$(AM_V_GEN)rm -f $@-t $@ && \
	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */' && \
	  sed -e '/definition of _Noreturn/r $(_NORETURN_H)' \
              < $(srcdir)/stdnoreturn.in.h; \
	} > $@-t && \
	mv $@-t $@
else
stdnoreturn.h: $(top_builddir)/config.status
	rm -f $@
endif
MOSTLYCLEANFILES += stdnoreturn.h stdnoreturn.h-t
EXTRA_DIST += stdnoreturn.in.h
EXTRA_DIST += verify.h

GENHDRS         = autoopts/options.h autoopts/usage-txt.h genshell.h \
		option-xat-attribute.h option-value-type.h ao-strs.h \
		ag-char-map.h
HDRS            = $(GENHDRS) autoopts.h project.h proto.h
GEN_SRC         = ao-strs.c option-value-type.c option-xat-attribute.c

## The primary source (autoopts.c) must be by itself on the first line after
## "CSRC".  'sed' does some magic here to get the list of source files for the
## documentation.  Files without documentation are on the CSRC = line.
##
CSRC            = parse-duration.c $(GEN_SRC) \
    autoopts.c \
    alias.c    boolean.c   check.c     configfile.c cook.c \
    enum.c     env.c       file.c      find.c       genshell.c \
    load.c     makeshell.c nested.c    numeric.c    pgusage.c \
    putshell.c reset.c     restore.c   save.c       sort.c \
    stack.c    streqvcmp.c text_mmap.c time.c       tokenize.c \
    usage.c    version.c   init.c

SRC             = $(HDRS) $(CSRC) $(GENSRC)
DEF_FILES       = genshell.def $(srcdir)/funcs.def ao-strs.def
pkgconfigdir    =$(libdir)/pkgconfig

## # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##
##   A U T O M A K E   V A R S
##
## # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

CLEANFILES                = tmp-* libopts.c
DISTCLEANFILES            = $(GENMAN) $(GENTEXI) *-stamp
MAINTAINERCLEANFILES      = $(GENHDRS) $(GENSRC) $(GENSCRIPTS)
m4datadir                 = $(datadir)/aclocal

nodist_libopts_la_SOURCES = libopts.c
libopts_la_SOURCES        = $(HDRS)
libopts_la_CFLAGS         = -DPKGDATADIR='"$(pkgdatadir)"'
libopts_la_LDFLAGS        = -version-info $(LIBOPTS_VER)
libopts_la_LIBADD         = $(top_builddir)/snprintfv/libsnprintfv.la

EXTRA_DIST += $(SRC) $(EXTRA_DATA) $(man_MANS) $(DEF_FILES)

INST_MANS                 = autoopts-config.1 $(GENMAN)
INST_PKGCFG               = pkgconfig/autoopts.pc
INST_LIBS                 = libopts.la
INST_HDRS                 = autoopts/options.h autoopts/usage-txt.h
INST_SH                   = autoopts-config

man_MANS                  = $(INST_MANS)
m4data_DATA               = autoopts.m4
pkgconfig_DATA            = $(INST_PKGCFG)
lib_LTLIBRARIES           = $(INST_LIBS)
nobase_include_HEADERS    = $(INST_HDRS)
bin_SCRIPTS               = $(INST_SH)

BOOTENV = AGexe="$(AGexe)" GDexe="$(GDexe)" CLexe="$(CLexe)" \
	srcdir="$(srcdir)"     top_srcdir="$(top_srcdir)"     \
	builddir="$(builddir)" top_builddir="$(top_builddir)" \
	AO_AGE="$(AO_AGE)"     AO_CURRENT="$(AO_CURRENT)"     \
	AO_REVISION="$(AO_REVISION)" POSIX_SHELL="$(POSIX_SHELL)"

## # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##
##   M A K E F I L E   R U L E S
##
## # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

libopts.c       : tpl-config-stamp
$(GENSCRIPTS)   : tpl-config-stamp

tpl-config-stamp: $(HDRS) $(CSRC) \
	    $(top_builddir)/config.h $(srcdir)/mk-tpl-config.sh
	LGCFLAGS="$(GUILE_CFLAGS)" \
	$(BOOTENV) \
	    $(POSIX_SHELL) $(srcdir)/mk-tpl-config.sh $@ $(HDRS) $(CSRC)

makeshell.lo    : genshell.c
genshell.c      : $(srcdir)/genshell.def
	$(BOOTENV) \
	    $(POSIX_SHELL) $(srcdir)/bootstrap.dir $@

strcspn.lo      : $(top_srcdir)/compat/strcspn.c
	$(LTCOMPILE) -o $@ -c $(top_srcdir)/compat/strcspn.c

install-data-local : install-man3

$(GENMAN)       : $(MAN_STAMP)
$(MAN_STAMP)    : $(srcdir)/funcs.def
	@test -x ../agen5/autogen || exit 0 ; \
	touch tmp-$@ ; \
	opts='-L$(srcdir)/tpl -L$(builddir)/tpl -Tagman3.tpl' ; \
	echo ! $(AGexe) $${opts} $(srcdir)/funcs.def ; \
	$(AGexe) $${opts} $(srcdir)/funcs.def ; \
	mv -f tmp-$@ $@

$(GENTEXI)      : $(TEXI_STAMP)
$(TEXI_STAMP)   : ../agen5/autogen $(srcdir)/funcs.def
	@touch tmp-$@ ; \
	opts='-L$(srcdir)/tpl -L$(builddir)/tpl -Taginfo3.tpl' ; \
	cmd="$(AGexe) $${opts} -DLEVEL=subsection -blibopts" ; \
	cmd="$${cmd} -L$(srcdir) $(srcdir)/funcs.def" ; \
	echo ! $$cmd ; $$cmd ; mv -f tmp-$@ $@

libsrc          : $(libsrc)
$(libsrc)       :
	@$(BOOTENV) \
	  AO_AGE=@AO_AGE@ AO_CURRENT=@AO_CURRENT@ AO_REVISION=@AO_REVISION@ \
	  $(POSIX_SHELL) $(top_srcdir)/pkg/libopts/mklibsrc.sh

pkgconfig/autoopts.pc : mk-autoopts-pc
	$(POSIX_SHELL) mk-autoopts-pc $@

install-data-hook:
	@DESTdestdir='$(DESTDIR)$(includedir)/autoopts' \
	DESTpkgdatadir='$(DESTDIR)$(pkgdatadir)' \
	DESTlibdatadir='$(DESTDIR)$(pkglibdir)' \
	top_builddir='$(top_builddir)' \
	LIBOPTS_VER='$(LIBOPTS_VER)' \
	POSIX_SHELL='$(POSIX_SHELL)'  \
	bindir='$(bindir)' \
	$(POSIX_SHELL) $(srcdir)/install-hook.sh

.NOTPARALLEL:

# Makefile.am ends here

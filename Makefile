########################################################
#
# Makefile for preparing leidenbase R package.
#
# This makefile is based on the R igraph Makefile.
# We acknowledge our use of Gabor Csardi's Makefile
# and our gratitude for his making the igraph
# distributions and source code publicly and
# freely available.
#
# Notes:
#   o  this make script creates a leidenbase package. It
#      is not distributed.
#
########################################################

all: leidenbase

########################################################

# Main package
# the R igraph *.tar.gz package file is untared in
# the leidenbase directory. The required igraph files
# are copied into the leidenbase/src/rigraph directory.
top_srcdir=igraph
VERSION_LEIDENBASE=0.1.18
VERSION_IGRAPH=$(shell cd igraph ; grep Version DESCRIPTION | awk 'BEGIN{FS=" "}{print $$2}')

# We put the version number in a file, so that we can detect
# if it changes

version_number: force
	@echo '$(VERSION_LEIDENBASE)' | cmp -s - $@ || echo '$(VERSION_LEIDENBASE)' > $@

# GSRC lists the R igraph files to be copied into src/rigraph. Additionally,
# the list is used to make lists of R igraph source code files, which are
# used build the library.
GSRC := $(shell cd $(top_srcdir) ; find . -type f -print | \
	sed "s/^\.\///" | \
	grep "^src")
# $(info GSRC is $(GSRC))
# $(info )

# Edit the GSRC by setting the directory part to
# the destination directories.
GSRC2 := $(patsubst src/%, src/rigraph/src/%, $(GSRC))
# $(info GSRC2 is $(GSRC2))
$(info )

# Copy the R igraph files to the src/rigraph destination.
$(GSRC2): src/rigraph/src/%: $(top_srcdir)/src/% src/rigraph
#	$(info file: $@)
#	$(info directory: $(@D))
	mkdir -p $(@D) && cp $< $@

# Ensure that the destination directory exits.
src/rigraph:
	mkdir -p src/rigraph

# Extract the C source code filenames.
CSRC2 := $(filter src/%.c,$(GSRC2))
# $(info CSRC2 is $(CSRC2))
# $(info)

# Extract the C++ source code filenames. These are the R igraph, leidenalg, and leidenbase C++ files.
CXXSRC2 := $(filter src/%.c++,$(GSRC2)) $(filter src/%.cxx,$(GSRC2)) $(filter src/%.cpp,$(GSRC2)) $(filter src/%.cc,$(GSRC2))
CXXSRC2 += $(shell cd src ; find . -maxdepth 1 -type f -print | egrep "\.(c++|cxx|cpp|cc)$$" | sed "s/\.\//src\//")
CXXSRC2 += $(shell cd src/leidenalg/src ; find . -maxdepth 1 -type f -print | egrep "\.(c++|cxx|cpp|cc)$$" | sed "s/\./src\/leidenalg\/src/")
# $(info CXXSRC2 is $(CXXSRC2))
# $(info)

# Extract FORTRAN source code filenames.
FSRC2 := $(filter src/%.f,$(GSRC2))
# $(info FORTRAN is $(FSRC2))
# $(info)


# R files that are generated/copied
# $(info make r files next)

RGEN = configure \
       configure.win \
       src/rigraph/configure \
       src/rigraph/src/config.h.in \
       src/Makevars.in \
       src/Makevars.win.in \
       DESCRIPTION \
       NEWS.md \
       src/rigraph/LICENSE \
       src/leidenalg/LICENSE

# configure apparently wants to find install-sh in the
# build directory when configure.ac has the macro
# AC_CONFIG_SUBDIRS(). The script has no function.
 src/config_aux_dir/install-sh: templates/install-sh.tpl src/config_aux_dir/install-sh
	mkdir -p src/config_aux_dir
	cp templates/install-sh.tpl src/config_aux_dir/install-sh

# configure files
# $(info make configure files next)

# Prepare configure and Makevars files. The initial files
# are in the leidenbase/templates directory.

# The leidenbase configure files.
configure: configure.ac src/config_aux_dir/install-sh
	autoconf -i

configure.win: configure.win.ac src/config_aux_dir/install-sh
	mkdir -p win_config
	cp configure.win.ac win_config/configure.ac
	cd win_config; autoconf -i; mv configure ../configure.win

# Make the R igraph configure file.
src/rigraph/configure src/rigraph/src/config.h.in: src/rigraph/configure.ac
	cd src/rigraph; autoheader; autoconf -i

# The template files.
configure.win.ac: templates/configure.win.ac.leidenbase.tpl check_templates
	sed 's/@VERSION@/'$(VERSION_LEIDENBASE)'/g' $< >$@

configure.ac: templates/configure.ac.leidenbase.tpl check_templates
	sed 's/@VERSION@/'$(VERSION_LEIDENBASE)'/g' $< >$@

src/rigraph/configure.ac: templates/configure.ac.igraph.tpl check_templates
	sed 's/@VERSION@/'$(VERSION_IGRAPH)'/g' $< >$@

src/Makevars.in: templates/Makevars.in.tpl object_files check_templates
	sed 's/@VERSION_IGRAPH@/'$(VERSION_IGRAPH)'/g' $< >$@
	printf "%s" "OBJECTS=" >> $@
	cat object_files >> $@

src/Makevars.win.in: templates/Makevars.win.in.tpl object_files check_templates
	sed 's/@VERSION_IGRAPH@/'$(VERSION_IGRAPH)'/g' $< >$@
	printf "%s" "OBJECTS=" >> $@
	cat object_files >> $@

check_templates:
	@echo "** Comparing templates to the destination files."
	@echo "** Check that the destinations are not newer than"
	@echo "** sources (templates)."
	@echo
	-@echo "** Compare configure.ac to templates/configure.ac.leidenbase.tpl" ; diff configure.ac templates/configure.ac.leidenbase.tpl ; echo
	-@echo "** Compare configure.win.ac to templates/configure.win.ac.leidenbase.tpl" ; diff configure.win.ac templates/configure.win.ac.leidenbase.tpl ; echo
	-@echo "** Compare src/rigraph/configure.ac to templates/configure.ac.igraph.tpl" ; diff src/rigraph/configure.ac templates/configure.ac.igraph.tpl ; echo
	-@echo "** Compare src/Makevars.in to templates/Makevars.in.tpl" ; diff src/Makevars.in templates/Makevars.in.tpl ; echo
	-@echo "** Compare src/Makevars.win.in to templates/Makevars.win.in.tpl" ; diff src/Makevars.win.in templates/Makevars.win.in.tpl ; echo
	@echo "** Stop if the destination files are modified without updating the templates." ; echo
	sleep 2

# DESCRIPTION file, we re-generate it only if the VERSION number
# changes
# $(info make description file next)

DESCRIPTION: templates/DESCRIPTION.tpl version_number
	sed 's/^Version: .*$$/Version: '$(VERSION_LEIDENBASE)'/' $< > $@

# LICENSE files for C igraph and leidenalg.
src/rigraph/LICENSE: LICENSE.GPL_2
	mkdir -p $(@D) && cp $< $@

src/leidenalg/LICENSE: LICENSE.GPL_3
	mkdir -p $(@D) && cp $< $@

# This is the list of all object files in the R package,
# we write it to a file to be able to depend on it.
# Makevars.in and Makevars.win.in are only regenerated if 
# the list of object files changes.
# $(info make objects list next)

OBJECTS := $(shell echo $(CSRC2) $(FSRC2) $(CXXSRC2) | \
           sed 's/ /\n/g' | \
           sed 's/^src\///' | \
           sed 's/\.f/\.o/' | \
           sed 's/\.cpp/\.o/' | \
           sed 's/\.c++/\.o/' | \
           sed 's/\.cxx/\.o/' | \
           sed 's/\.cc/\.o/' | \
           sed 's/\.c/\.o/' | \
           tr '\n' ' ' | \
           sed 's/ $$//')

# $(info OBJECTS $(OBJECTS))
# $(info)

# Write the required object files to a file called object_file, which
# is appended to the Makevars.in file.
.INTERMEDIATE: object_files
object_files: force
	@echo '$(OBJECTS)' | cmp -s - $@ || echo '$(OBJECTS)' > $@

# We have everything, here we go

leidenbase: leidenbase_$(VERSION_LEIDENBASE).tar.gz

leidenbase_$(VERSION_LEIDENBASE).tar.gz: $(GSRC2) $(RGEN)
	chmod 700 configure
	chmod 700 src/rigraph/configure
	Rscript -e 'devtools::build(path = ".", vignettes=FALSE)'

clean:
	rm -f \
      configure \
      configure.ac \
      configure.win \
      configure.win.ac \
      config.log \
      config.status \
      DESCRIPTION \
      object_files \
      object.out \
      src/*.o \
      src/Makevars \
      src/Makevars.in \
      src/Makevars.win \
      src/Makevars.win.in \
      src/leidenalg/src/*.o \
      src/rigraph/config.log \
      src/rigraph/config.status \
      src/rigraph/configure \
      src/rigraph/configure.ac \
      src/rigraph/src/*.o \
      src/rigraph/src/config.h \
      src/rigraph/src/bliss/*.o \
      src/rigraph/src/cliquer/*.o \
      src/rigraph/src/cs/*.o \
      src/rigraph/src/plfit/*.o \
      src/rigraph/src/prpack/*.o \
      src/rigraph/src/simpleraytracer/*.o \
      src/rigraph/src/SuiteSparse_config/*.o \
      src/rigraph/src/uuid/*.o
	rm -rf win_config \
      src/rigraph/autom4te.cache


#############

.PHONY: all leidenbase force leidenbase_$(VERSION_LEIDENBASE).tar.gz



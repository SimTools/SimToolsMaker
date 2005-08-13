
SimToolsDir=$(subst src,SimTools,$(shell pwd))
SimToolsVersion=1-02

PACKAGES = lcbase Leda lclib jsf physsim Jupiter Satellites Uranus
TMPDIR   = $(SimToolsDir)/../tmp
WEBDIR   = $(SimToolsDir)/../web
EXAMPLEDIR = $(SimToolsDir)/examples
SimToolsBinDir=$(TMPDIR)/SimTools-$(SimToolsVersion)-bin
SimToolsSrcDir=$(TMPDIR)/SimTools-$(SimToolsVersion)-src

# PACKAGES = lcbase Leda 
CVS_CHECKOUT_CMD = cvs -q -d /proj/soft/CVSMASTER co -P 
CVS_EXPORT_CMD = cvs -q -d /proj/soft/CVSMASTER export -r SimTools-1-02

# all: makefiles checkout build examples bintar srctar
all: examples bintar srctar

bintar:
	( cd $(SimToolsDir) && cp -rp tools $(SimToolsBinDir) )
	( cd $(SimToolsBinDir)/tools/Jupiter && rm -rf tmp )
	( cd $(SimToolsBinDir)/tools/Leda && rm -rf src )
	( cd $(SimToolsBinDir)/tools/Satellites && rm -rf src )
	( cd $(SimToolsBinDir)/tools/Uranus && rm -rf src )
	( cd $(SimToolsBinDir)/tools/jsf  && rm -rf src )
	( cd $(SimToolsBinDir)/tools/lclib && rm -rf gen util  ) 
	( cd $(SimToolsBinDir)/tools/lclib/simjlc && rm -rf src Makefile )
	( cd $(SimToolsBinDir)/tools/physsim && \
	   find -type f -name "*.o" -exec rm {} \; )
	( cp -rp $(SimToolsDir)/examples $(SimToolsBinDir) )
	( cp -p $(SimToolsDir)/setup.bash $(SimToolsBinDir) )
	( cp -p $(SimToolsDir)/Readme $(SimToolsBinDir) )
	( cp -rp $(SimToolsDir)/docs $(SimToolsBinDir) )
	( cd $(SimToolsBinDir)/.. && \
	  tar -zcvf SimTools-$(SimToolsVersion)-bin.tar.gz \
	  SimTools-$(SimToolsVersion)-bin ) \
	> $(TMPDIR)/jobout.bintar 

srctar:
	( for p in $(PACKAGES) ; do \
	  ( cd $(SimToolsSrcDir)/tools && \
	  $(CVS_EXPORT_CMD) $$p )  ; \
	  done ) 
	( cp -rp $(SimToolsDir)/examples $(SimToolsSrcDir) ) 
	( cp -p $(SimToolsDir)/setup.bash $(SimToolsSrcDir) )
	( cp -p $(SimToolsDir)/Readme $(SimToolsSrcDir) ) 
	( cp -rp $(SimToolsDir)/docs $(SimToolsSrcDir) ) 
	( cd $(SimToolsSrcDir)/.. && \
	  tar -zcf SimTools-$(SimToolsVersion)-src.tar.gz \
	  SimTools-$(SimToolsVersion)-src ) 
	> $(TMPDIR)/jobout.srctar 

examples: jsf_quicksim_example satellites_example jupiter_example

html: 
	( cd $(SimToolsDir) && source setup-build.bash && \
	  cd docs && \
	  jsf -b -q ../html.C && \
	  jsf -b -q ../html_script.C ) > $(TMPDIR)/jobout.html 2>&1 

satellites_example:
	( cd $(SimToolsDir) && \
	source setup-build.bash && \
	cd examples && \
	../build_all make_satellites_examples ) \
	> $(TMPDIR)/jobout.satellites_examples 2>&1 

jsf_quicksim_example:
	( cd $(SimToolsDir) && \
	source setup-build.bash && \
	cd examples && \
	../build_all make_jsf_quicksim_examples ) \
	> $(TMPDIR)/jobout.jsf_quicksim_examples 2>&1 

jupiter_example:
	( cd $(SimToolsDir) && \
	source setup-build.bash && \
	cd examples && \
	../build_all make_jupiter_examples ) \
	> $(TMPDIR)/jobout.jupiter_examples 2>&1 

makefiles:
	mkdir -p $(SimToolsDir)/tools $(TMPDIR) $(EXAMPLEDIR) $(WEBDIR)
	mkdir -p $(SimToolsBinDir) $(SimToolsSrcDir)/tools
	cpp -P -C -D SIMTOOLS setup.bash > $(SimToolsDir)/setup.bash
	cpp -P -C -D BUILD setup.bash > $(SimToolsDir)/setup-build.bash
	cpp -P -C setup.bash > $(SimToolsDir)/setup-jlclogin.bash
	cp -p build_all html.C html_script.C Readme $(SimToolsDir)
	cp -rp docs $(SimToolsDir)

checkout:
	( for p in $(PACKAGES) ; do \
	  ( cd $(SimToolsDir)/tools && \
	  $(CVS_EXPORT_CMD) $$p )  ; \
	  done ) > $(TMPDIR)/jobout.cvs_checkout 2>&1

build:
	( cd $(SimToolsDir) && \
	./build_all "source setup-build.bash" build_package ) \
	> $(TMPDIR)/jobout.build 2>&1 

cleanall:
	rm -rf $(SimToolsDir) $(TMPDIR)

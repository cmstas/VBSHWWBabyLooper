SUBDIRS := $(sort $(dir $(wildcard studies/*/.)))
LIBRARIES := NanoTools/NanoCORE VBSHWWCORE rooutil

all: $(LIBRARIES) $(SUBDIRS)

NanoCORE:
	$(MAKE) -C NanoTools/NanoCORE

VBSHWWCORE:
	$(MAKE) -C VBSHWWCORE

rooutil:
	$(MAKE) -C rooutil

minilooper:
	$(MAKE) -C minilooper

$(SUBDIRS): NanoCORE VBSHWWCORE rooutil minilooper
	$(MAKE) -C $@

.PHONY: all $(LIBRARIES) $(SUBDIRS)

clean:
	cd studies/mainAnalysis && make clean;
	cd studies/createMini && make clean;

cleanall:
	cd VBSHWWCORE/ && make clean;
	cd rooutil/ && make clean;
	cd NanoTools/NanoCORE/ && make clean;
	cd studies/mainAnalysis && make clean;
	cd studies/createMini && make clean;
	cd studies/extraJets && make clean;
	cd studies/bdtInputs && make clean;
	cd studies/philipSR && make clean;

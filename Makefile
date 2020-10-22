COMMIT_HASH = 6e984cc
REPO_URL    = https://raw.githubusercontent.com/rollbear/trompeloeil
TARGETS     = inst/include/trompeloeil.hpp inst/include/testthat/trompeloeil.hpp

all: $(TARGETS)

clean:
	rm $(TARGETS)

inst/include/trompeloeil.hpp: inst/include/trompeloeil.patch
	curl $(REPO_URL)/$(COMMIT_HASH)/include/trompeloeil.hpp -o \
		inst/include/trompeloeil.hpp;\
	patch -d inst/include < inst/include/trompeloeil.patch

inst/include/testthat/trompeloeil.hpp: inst/include/testthat/trompeloeil.patch
	curl $(REPO_URL)/$(COMMIT_HASH)/include/catch2/trompeloeil.hpp -o \
		inst/include/testthat/trompeloeil.hpp;\
	patch -d inst/include/testthat < inst/include/testthat/trompeloeil.patch

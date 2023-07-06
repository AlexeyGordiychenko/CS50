CC=gcc
CFLAGS=-Wall -Werror -Wextra

BLD_PATH=build
DB_PATH=db
DEFAULT_DB_PATH=initial_tables

all: cli check

cli:
	$(CC) $(CFLAGS) cli.c login.c modules.c doors.c shared.c -o $(BLD_PATH)/cli

check:
	$(CC) $(CFLAGS) check.c shared.c -o $(BLD_PATH)/check

copy_db:
	cp $(DEFAULT_DB_PATH)/* $(BLD_PATH)/$(DB_PATH)/

clean:
	rm -rf $(BLD_PATH)/cli $(BLD_PATH)/check

rebuild: clean all
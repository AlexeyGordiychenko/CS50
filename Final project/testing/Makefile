BLD_PATH=../build
DEFAULT_DB_PATH=../initial_tables
DB_PATH=db/
 
all: test_cli test_check
 
test_cli:
	$(MAKE) copy_executables

#	test_menu
	$(MAKE) copy_tables
	cp test_menu.txt test.txt
	$(MAKE) run_valgrind_cli
	diff test_menu_ref.txt test_output.txt
	echo "test_menu_completed"

#	test_login
	$(MAKE) copy_tables
	cp test_login.txt test.txt
	$(MAKE) run_valgrind_cli
	diff test_login_ref.txt test_output.txt
	echo "test_login_completed"

#	test_modules
	$(MAKE) copy_tables
	cp test_modules.txt test.txt
	$(MAKE) run_valgrind_cli
	diff test_modules_ref.txt test_output.txt
	echo "test_modules_completed"

#	test_doors
	$(MAKE) copy_tables
	cp test_doors.txt test.txt
	$(MAKE) run_valgrind_cli
	diff test_doors_ref.txt test_output.txt
	echo "test_doors_completed"

#	test_corrupted_database
	$(MAKE) clean_db
	cp test_corrupted_database.txt test.txt
	$(MAKE) run_valgrind_cli
	diff test_corrupted_database_ref.txt test_output.txt
	echo "test_corrupted_database_completed"

#	clean
	$(MAKE) clean_tmp_files
	$(MAKE) clean_executables
	echo "test_cli_completed"

test_check:
	$(MAKE) copy_executables
	$(MAKE) run_valgrind_check
	cp $(DEFAULT_DB_PATH)/login $(DB_PATH)/
	$(MAKE) run_valgrind_check
	cat test_check_ins_incorrect_login.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	cat test_check_update_login.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	cp $(DEFAULT_DB_PATH)/modules $(DB_PATH)/
	$(MAKE) run_valgrind_check
	cat test_check_rename_security.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	cp $(DEFAULT_DB_PATH)/modules $(DB_PATH)/
	$(MAKE) run_valgrind_check
	cat test_check_delete_security.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	cp $(DEFAULT_DB_PATH)/doors $(DB_PATH)/
	$(MAKE) run_valgrind_check
	cat test_check_unlock_one_door.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	cat test_check_unlock_all_doors.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	cp $(DEFAULT_DB_PATH)/doors $(DB_PATH)/
	$(MAKE) run_valgrind_check
	cat test_check_delete_all_doors.txt | ./cli >> test_check_output.txt
	$(MAKE) run_valgrind_check
	diff test_check_ref.txt test_check_output.txt
	$(MAKE) clean
	echo "test_check_completed"

copy_tables:
	cp $(DEFAULT_DB_PATH)/* $(DB_PATH)/

clean: clean_executables clean_db clean_tmp_files

reset: clean copy_executables copy_tables

clean_executables:
	rm cli check || true

clean_db:
	rm $(DB_PATH)/* || true

clean_tmp_files:
	rm test_output.txt test.txt val.txt test_check_output.txt || true

copy_executables:
	cp $(BLD_PATH)/cli .
	cp $(BLD_PATH)/check .	

run_valgrind_check:
	valgrind --log-file=val.txt ./check >> test_check_output.txt && cat val.txt | grep LEAK >> test_check_output.txt || true

run_valgrind_cli:
	cat test.txt | valgrind --log-file=val.txt ./cli > test_output.txt && cat val.txt | grep LEAK >> test_output.txt || true
.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_4 - Debug ]----------"
	@cd "Lab_4" && "$(MAKE)" -f  "Lab_4.mk"
clean:
	@echo "----------Cleaning project:[ Lab_4 - Debug ]----------"
	@cd "Lab_4" && "$(MAKE)" -f  "Lab_4.mk" clean

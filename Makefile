.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_7 - Debug ]----------"
	@cd "Lab_7" && "$(MAKE)" -f  "Lab_7.mk"
clean:
	@echo "----------Cleaning project:[ Lab_7 - Debug ]----------"
	@cd "Lab_7" && "$(MAKE)" -f  "Lab_7.mk" clean

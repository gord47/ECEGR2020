.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_5 - Debug ]----------"
	@cd "Lab_5" && "$(MAKE)" -f  "Lab_5.mk"
clean:
	@echo "----------Cleaning project:[ Lab_5 - Debug ]----------"
	@cd "Lab_5" && "$(MAKE)" -f  "Lab_5.mk" clean

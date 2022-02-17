.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_3 - Debug ]----------"
	@cd "Lab_3" && "$(MAKE)" -f  "Lab_3.mk"
clean:
	@echo "----------Cleaning project:[ Lab_3 - Debug ]----------"
	@cd "Lab_3" && "$(MAKE)" -f  "Lab_3.mk" clean

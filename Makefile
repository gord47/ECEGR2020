.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_0 - Debug ]----------"
	@cd "Lab_0" && "$(MAKE)" -f  "Lab_0.mk"
clean:
	@echo "----------Cleaning project:[ Lab_0 - Debug ]----------"
	@cd "Lab_0" && "$(MAKE)" -f  "Lab_0.mk" clean

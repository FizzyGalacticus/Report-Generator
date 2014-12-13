function Component()
{
	// constructor
}

Component.prototype.isDefault = function()
{
	// select the component by default
	return true;
}

Component.prototype.createOperations = function()
{
	try {
		// call the base create operations function
		component.createOperations();
	} 
	catch (e) {
		print(e);
	}
	
	if (installer.value("os") === "win")
	{
		component.addOperation("CreateShortcut", "@TargetDir@/Report-Generator.exe", "@DesktopDir@/CWI Report Generator.lnk");
	}
}
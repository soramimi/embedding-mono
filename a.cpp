
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>


int main(int argc, char **argv)
{
	mono_config_parse(nullptr);

	MonoDomain *domain = mono_jit_init("b.dll");
	if (!domain) return 1;

	MonoAssembly *assembly = mono_domain_assembly_open(domain, "b.dll");
	if (!assembly) return 1;

	MonoImage *image = mono_assembly_get_image(assembly);
	MonoClass *klass = mono_class_from_name(image, "Test", "Class1");
	MonoMethodDesc *desc = mono_method_desc_new(":Add(int,int,int)", false);
	MonoMethod *static_method = mono_method_desc_search_in_class(desc, klass);

	void *args[3];
	int val1 = 12;
	int val2 = 34;
	int val3 = 56;
	args[0] = &val1;
	args[1] = &val2;
	args[2] = &val3;
	MonoObject *ret = mono_runtime_invoke(static_method, NULL, args, NULL);
	int result = *(int *)mono_object_unbox(ret);

	mono_jit_cleanup(domain);
	
	printf("%d\n", result);

	return 0;
}

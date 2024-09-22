    static void LoadInternal(DatabaseInstance &instance) {
            auto my_table_func = TableFunction("query_json_api", {}, my_table_function, my_bind_function, my_init_function);
        my_table_func.filter_pushdown = false;
        my_table_func.projection_pushdown = true;    
        my_table_func.cardinality = my_cardinality;
        my_table_func.pushdown_complex_filter = PushdownComplexFilter;

        my_table_func.named_parameters["options"] = LogicalType::VARCHAR;
        my_table_func.named_parameters["api"] = LogicalType::VARCHAR;

        ExtensionUtil::RegisterFunction(instance, my_table_func);
        
        auto &config = DBConfig::GetConfig(instance);

        config.AddExtensionOption("rest_api_config_file", "REST API Config File Location", LogicalType::VARCHAR,
                                Value("/users/thisguy/rest_api_extension.json"));

    }
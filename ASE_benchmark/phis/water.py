phi = [
    # !(request_startup) | (X access_granted | X help_displayed | X system_news_displayed)
    "!request_startup | X access_granted | X help_displayed | X system_news_displayed",

    # !(generate_well_package) | (F well_file_generated | F error_logged | F process_logged)
    "!generate_well_package | F well_file_generated | F error_logged | F process_logged",

    # !(update_parameters) | (F recalculated_values | F warning_displayed | F derived_data_displayed)
    "!update_parameters | F recalculated_values | F warning_displayed | F derived_data_displayed",

    # !(view_map) | (F show_pumpage | F show_permit_zones | F show_aquifer_overlay)
    "!view_map | F show_pumpage | F show_permit_zones | F show_aquifer_overlay",

    # !(view_report) | (F historical_use_data | F trend_graphs | F compliance_flag)
    "!view_report | F historical_use_data | F trend_graphs | F compliance_flag",

    # Lapsed quantities OR MFL zone OR expired permit must eventually appear
    "F lapsed_quantities_displayed | F MFL_zone_identified | F permit_status_expired",

    # !(view_compliance) | (F inferred_compliance | F flat_values_detected | F zero_pumpage_reported)
    "!view_compliance | F inferred_compliance | F flat_values_detected | F zero_pumpage_reported",

    # !(query_by_date) | (F status_active | F status_expired | F status_pending)
    "!query_by_date | F status_active | F status_expired | F status_pending",

    # !(view_water_use_permit) | (F permit_details | F usage_chart | F map_overlay)
    "!view_water_use_permit | F permit_details | F usage_chart | F map_overlay",

    # !(view_withdrawal_info) | (F aquifer_type | F source_type | F withdrawal_depth)
    "!view_withdrawal_info | F aquifer_type | F source_type | F withdrawal_depth",

    # !(view_net_benefit_summary) | (F permit_reactivated | F quantity_reduced | F relocation_tracked)
    "!view_net_benefit_summary | F permit_reactivated | F quantity_reduced | F relocation_tracked",

    # !(view_report) | (F permit_updated | F usage_recalculated | F compliance_checked)
    "!view_report | F permit_updated | F usage_recalculated | F compliance_checked",

    # If system starts, user role is determined OR general features are granted OR startup info shown
    "!startup_requested | X(user_role_determined | general_features_granted | startup_info_displayed)",

    # If permit is issued, it must eventually appear on the map OR in permit list OR generate compliance check
    "!permit_issued | F(map_updated | permit_listed | compliance_checked)",

    # If land use changes, show updated usage OR calculate impact OR send notification
    "!land_use_changed | F(water_use_updated | impact_calculated | district_alerted)",

    # Report must contain graph OR chart OR MFL comparison, always
    "G(report_viewed -> (F(graph_shown | chart_rendered | mfl_compared)))",

    # Long requirement: Either pumpage submitted, OR estimated OR interpolated, AND report updates eventually
    "(pumpage_submitted | estimated_from_neighbors | interpolated_data) & F(report_updated)",

    # Complex logic: If aquifer stressed, eventually augment OR pump less OR notify staff
    "!aquifer_stressed | F(augment_source | reduce_pumping | staff_notified)",

    # Data not submitted implies fallback estimation OR compliance flag OR alert sent
    "!data_submitted | F(estimate_used | compliance_flagged | alert_sent)",

    # If crop report received then it leads to soil match OR acre calc OR usage mapping
    "!crop_report_received | X(soil_matched | acreage_calculated | usage_mapped)",

    # Complex: Always if historical unused quantity exists, it will not be relocated OR reused OR repurposed
    "G(historical_unused_quantity -> !(relocated | reused | repurposed))",

    # Long & winding: If compliance fails and overpumping OR zero data, show alert or deny renewal
    "!compliance_passed | ((overpumping | missing_data | zero_usage) & F(alert_shown | renewal_denied))",

    # If ERP is applied and WUP exists then notify staff OR trigger review OR mark as conflict
    "!(erp_applied & wup_exists) | F(staff_notified | review_triggered | flagged_conflict)",

    # Always show crop report OR land use OR aquifer source if permit viewed
    "G(permit_viewed -> (F(crop_report_shown | land_use_displayed | aquifer_identified)))"
]
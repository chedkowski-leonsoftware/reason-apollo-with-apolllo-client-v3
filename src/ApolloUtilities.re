type operationDefinitionNode = {
  kind: string,
  operation: string,
};

[@bs.module "@apollo/client/utilities"]
external getMainDefinition:
  ReasonApolloTypes.documentNodeT => operationDefinitionNode =
  "getMainDefinition";

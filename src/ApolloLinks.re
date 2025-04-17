open ReasonApolloTypes;

/* Bind the method `from`, used to compose links together */
[@bs.module "@apollo/client"]
external from: array(apolloLink) => apolloLink = "from";

/* Bind the method split. Based on a test send left or right */
[@bs.module "@apollo/client"]
external split: (splitTest => bool, apolloLink, apolloLink) => apolloLink =
  "split";

/* Bind the HttpLink class */
[@bs.module "@apollo/client"] [@bs.new]
external createHttpLink: ApolloClient.linkOptions => apolloLink = "HttpLink";

/* Bind the setContext method */
[@bs.module "@apollo/client/link/context"]
external apolloLinkSetContext: (unit => Js.t({..})) => apolloLink =
  "setContext";

/* Bind the onError method */
[@bs.module "@apollo/client/link/error"]
external apolloLinkOnError: (errorResponse => unit) => apolloLink = "onError";

/* bind apollo-link-ws */
[@bs.module "@apollo/client/link/ws"] [@bs.new]
external webSocketLink: webSocketLinkT => apolloLink = "WebSocketLink";

// let webSocketLink = (~uri, ~reconnect=?, ~connectionParams=?, ()) => {
//   uri,
//   options: {
//     reconnect,
//     connectionParams,
//   },
// };

/**
 * CreateHttpLink
 * https://github.com/apollographql/apollo-link/tree/master/packages/apollo-link-http
 */
let createHttpLink =
    (
      ~uri,
      ~includeExtensions=?,
      ~fetch=?,
      ~headers=?,
      ~credentials=?,
      ~fetchOptions=?,
      (),
    ) => {
  createHttpLink({
    uri,
    includeExtensions: Js.Nullable.fromOption(includeExtensions),
    fetch: Js.Nullable.fromOption(fetch),
    headers: Js.Nullable.fromOption(headers),
    credentials: Js.Nullable.fromOption(credentials),
    fetchOptions: Js.Nullable.fromOption(fetchOptions),
  });
};

/**
 * CreateContextLink
 * https://github.com/apollographql/apollo-link/tree/master/packages/apollo-link-context
 */
let createContextLink = contextHandler => {
  /* Instanciate a new context link object */
  apolloLinkSetContext(
    contextHandler,
  );
};

/**
 * CreateErrorLink
 * https://github.com/apollographql/apollo-link/tree/master/packages/apollo-link-error
 */
let createErrorLink = errorHandler => {
  /* Instanciate a new error link object */
  apolloLinkOnError(errorHandler);
};
